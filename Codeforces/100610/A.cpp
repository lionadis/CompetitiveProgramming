#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[10],b[10];
int main(){

	freopen("acm.in", "r", stdin);
    freopen("acm.out", "w", stdout);
	string s = "";
    cin>>n>>m;
    int a;
    for (int i=0;i<n;i++){
        cin>>a;
        if (i!=0)
        		s+="*";
 		 s+="(10";
        for (int j=0;j<a;j++)
        	s+="-1";
        s+=")";
    }

    s+="=0";

    cout<<s<<'\n';
	return 0;
}