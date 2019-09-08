#include <bits/stdc++.h>
using namespace std;
char s[111][70];
int l, m, p[111], c[111], t[111], r[111];
bool ok[111];
int main(){
	//freopen("test.in", "r+", stdin);
	scanf("%d %d\n", &l, &m);
	int min_p = 111111;
	for(int i = 0; i < m; i++){
		//scanf("%[^,]%*c%d%*c%d%*c%d%*c%d\n", s,&p,&c,&t,&r);
		scanf("%[^,],%d,%d,%d,%d\n", s[i],&p[i],&c[i],&t[i],&r[i]);
		if(10080 * c[i] * t[i] / (t[i] + r[i]) >= l){
			ok[i] = true;
			if(p[i] < min_p)min_p = p[i];
		}
	}
	if(min_p == 111111)printf("no such mower\n");
	else{
		for(int i = 0; i < m; i++){
			if(p[i] == min_p && ok[i])printf("%s\n", s[i]);
		}
	}
	
}
