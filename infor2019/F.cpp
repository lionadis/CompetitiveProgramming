#include <bits/stdc++.h>

using namespace std;

bool isOperator(char c) 
{ 
    return (!isalpha(c)); 
} 

int getPriority(char C) 
{ 	if(C == '!')
		return 3;
    else if (C == ',') 
        return 2;
    else if(C == ';')
		return 1;
    return 0;
}

string infixToPrefix(string infix) 
{ 
    // stack for operators. 
    stack<char> operators; 
  
    // stack for operands. 
    stack<string> operands; 
  
    for (int i = 0; i < (int)infix.length(); i++) {
        if (infix[i] == '(') { 
            operators.push(infix[i]); 
        } 
        else if (infix[i] == ')') { 
            while (!operators.empty() &&  !operands.empty() && 
                   operators.top() != '(') {
					// operator 
					char op = operators.top(); 
					operators.pop();
					if(op == '!'){
						string tmp = operands.top();
						operands.pop();
						operands.push(op + tmp);
					} else {
						// operand 1 
						string op1 = operands.top(); 
						operands.pop(); 
		  
						// operand 2 
						string op2 = operands.top(); 
						operands.pop(); 
						
						string tmp = op + op2 + op1; 
						operands.push(tmp); 
					}
					   
					   
            }
            operators.pop(); 
        }
        else if (!isOperator(infix[i])) { 
            operands.push(string(1, infix[i])); 
        } 
        else { 
            while (!operators.empty() &&  !operands.empty() && 
                   getPriority(infix[i]) <=  
                     getPriority(operators.top())) {
                // operator 
                char op = operators.top(); 
                operators.pop();
                if(op == '!'){
					string tmp = operands.top();
					operands.pop();
					operands.push(op + tmp);
				} else {
					// operand 1 
					string op1 = operands.top(); 
					operands.pop(); 
	  
					// operand 2 
					string op2 = operands.top(); 
					operands.pop(); 
					
					string tmp = op + op2 + op1; 
					operands.push(tmp); 
				}
            }
            operators.push(infix[i]);
        } 
    } 

    while (!operators.empty() && !operands.empty()) { // operator 
		char op = operators.top(); 
		operators.pop();
		if(op == '!'){
			string tmp = operands.top();
			operands.pop();
			operands.push(op + tmp);
		} else {
			// operand 1 
			string op1 = operands.top(); 
			operands.pop(); 

			// operand 2 
			string op2 = operands.top(); 
			operands.pop(); 
			
			string tmp = op + op2 + op1; 
			operands.push(tmp); 
		}
    }  
    return operands.top(); 
}



int main(){
	freopen("test.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, p;
	cin >> n >> p;
	unordered_map<char, unordered_map<string, bool> > predicats;
	for(int i = 0; i < p; ++ i){
		string pred;
		cin >> pred;
		for(int j = 0; j < n; ++ j){
			string exp;
			cin >> exp;
			string val, var;
			stringstream ss(exp);
			getline(ss, val, ',');
			getline(ss, var, ',');
			predicats[pred[0]][var] = (val == "true");
		}
	}
	int n_pred;
	cin >> n_pred;
	while(n_pred--){
		string exp;
		cin >> exp;
		string prefix_exp = infixToPrefix(exp);
		int n_queries;
		cin >> n_queries;
		while(n_queries--){
			string var;
			cin >> var;			
			stack<bool> st;
			for(int i = (int)prefix_exp.size() - 1; i >= 0; -- i){
				if(!isOperator(prefix_exp[i])){
					st.push(predicats[prefix_exp[i]][var]);
				} else {
					if(prefix_exp[i] == '!'){	
						bool op = st.top();
						st.pop();
						st.push(!op);
					} else {						
						bool op1 = st.top();
						st.pop();
						bool op2 = st.top();
						st.pop();
						if(prefix_exp[i] == ',') st.push(op1 && op2);
						else st.push(op2 || op1);
					}
				}
			}
			cout << (st.top() ? "true\n":"false\n");
		}
	}	
}
		
		
