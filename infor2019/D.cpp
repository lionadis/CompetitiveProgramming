#include <bits/stdc++.h>

using namespace std;

bool isOperator(char c) 
{ 
    return (!isalpha(c)); 
} 

int getPriority(char C) 
{ 
    if (C == ',') 
        return 2;
    else if(C == ';')
		return 1;
    return 0;
}

string infixToPrefix(char* infix) 
{ 
    // stack for operators. 
    stack<char> operators; 
  
    // stack for operands. 
    stack<string> operands; 
  
    for (int i = 0; i < (int)strlen(infix); i++) { 

        if (infix[i] == '(') { 
            operators.push(infix[i]); 
        } 

        else if (infix[i] == ')') { 
            while (!operators.empty() &&  
                   operators.top() != '(') { 
  
                // operand 1 
                string op1 = operands.top(); 
                operands.pop(); 
  
                // operand 2 
                string op2 = operands.top(); 
                operands.pop(); 
  
                // operator 
                char op = operators.top(); 
                operators.pop(); 
 
                string tmp = op + op2 + op1; 
                operands.push(tmp); 
            } 
 
            operators.pop(); 
        } 
 
        else if (!isOperator(infix[i])) { 
            operands.push(string(1, infix[i])); 
        } 

        else { 
            while (!operators.empty() &&  
                   getPriority(infix[i]) <=  
                     getPriority(operators.top())) { 
  
                string op1 = operands.top(); 
                operands.pop(); 
  
                string op2 = operands.top(); 
                operands.pop(); 
  
                char op = operators.top(); 
                operators.pop(); 
  
                string tmp = op + op2 + op1; 
                operands.push(tmp); 
            } 
  
            operators.push(infix[i]); 
        } 
    } 

    while (!operators.empty()) { 
        string op1 = operands.top(); 
        operands.pop();
        string op2 = operands.top(); 
        operands.pop();
        char op = operators.top(); 
        operators.pop();
        string tmp = op + op2 + op1; 
        operands.push(tmp); 
    }  
    return operands.top(); 
}

char expr[100000];

int main(){
	freopen("test.in", "r", stdin);
	int n, p;
	scanf("%d\n",&n);
	scanf("%d\n",&p);
	unordered_map<char, unordered_map<int, bool> > predicats;
	predicats.reserve(1024);
	predicats.max_load_factor(0.25);
	unordered_map<string, int> ids;
	ids.reserve(1024);
	ids.max_load_factor(0.25);
	int id = 0;
	for(int i = 0; i < p; ++ i){
		char pred;
		scanf("%c\n", &pred);
		for(int j = 0; j < n; ++ j){
			char exp[20];
			scanf("%s\n", exp);
			char *val = strtok(exp, ",");
			char *c_var = strtok(NULL, ",");
			string s_var = string(c_var);
			int var = -1;
			if(ids.count(s_var)) var = ids[s_var];
			else var = ids[s_var] = id++;
			predicats[pred][var] = (val[0] == 't');
		}
	}
	int n_pred;
	scanf("%d\n", &n_pred);
	while(n_pred--){
		scanf("%s\n", expr);
		string prefix_exp = infixToPrefix(expr);
		// cout << prefix_exp << '\n';
		int n_queries;
		scanf("%d\n", &n_queries);
		while(n_queries--){
			char c_var[20];
			scanf("%s\n", c_var);
			string s_var = string(c_var);
			int var = ids[s_var];	
			stack<bool> st;
			for(int i = (int)prefix_exp.size() - 1; i >= 0; -- i){
				if(!isOperator(prefix_exp[i])){
					st.push(predicats[prefix_exp[i]][var]);
				} else {
					bool op1 = st.top();
					st.pop();
					bool op2 = st.top();
					st.pop();
					if(prefix_exp[i] == ',') st.push(op1 && op2);
					else st.push(op2 || op1);
				}
			}
			if(st.top()) printf("true\n");
			else printf("false\n");
		}
	}	
}
