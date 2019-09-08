#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("test.in", "r", stdin);	
	int n;
	scanf("%d\n", &n);
	while(n--){
		char s[12];
		scanf("%s", s);
		char *a = strtok(s, ",");
		char *b = strtok(NULL, ",");
		printf("%s %s\n", a, b);
	}
}
		
		
