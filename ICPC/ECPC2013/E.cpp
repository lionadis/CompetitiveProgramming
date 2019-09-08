#include <bits/stdc++.h>

#define rep(i,a,b) for(int i=a;i<(b);++i)
#define F first
#define S second
#define sz(a) (a).size()

using namespace std;

int main(){
    int tc=0;
    freopen("ghanophobia.in", "r+",stdin);
    int n; cin>> n;
    while(n--){
        cout<<"Case "<<++tc<<": ";
        int a,b;
        scanf("%d:%d",&a,&b);
        if(a==6&&b==1)cout<<"PENALTIES\n";
        else if(a+1>b+6)cout<<"YES\n";
        else if(a+1<b+6)cout<<"NO\n";
        else {
            b*=2;
            if(a+2>b+6)cout<<"YES\n";
            if(a+2<b+6)cout<<"NO\n";
        }
    }
}
