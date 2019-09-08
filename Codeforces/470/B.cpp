#include <bits/stdc++.h>
using namespace std;
int x0,x1,x2;
vector<int> P;
bool prime[100001];
vector<int> prime_factors1;
vector<int> prime_factors2;
void sieve(){
    memset(prime,true,sizeof prime);
    for(int i=2;i<=10000;i++){
        if(prime[i]){
            P.push_back(i);
            for(int j=2*i;j<=10000;j+=i)
                prime[j]=false;
        }
    }
}
void pf(int n, vector<int> &prime_factors){
    int nn = n;
    prime_factors.clear();
    int idx = 0;
    while(idx<P.size() && P[idx]*P[idx]<=n){
        if(n%P[idx]==0)prime_factors.push_back(P[idx]);
        while(n%P[idx]==0)n/=P[idx];
        idx++;
    }
    if(n!=1 && n!=nn)prime_factors.push_back(n);
}
int main(){
    sieve();
    x0 = 10000000;
    cin>>x2;
    pf(x2,prime_factors2);
    for(x1 = 3; x1<=x2; x1++){
        for(auto p2: prime_factors2){
            if(ceil(double(x1)/p2)*p2 != x2)continue;
            pf(x1,prime_factors1);
            for(auto p1: prime_factors1){
                x0 = min(x0, (x1/p1 -1)*p1 +1);
            }
            
        }
    }
    cout<<x0<<endl;
    
}