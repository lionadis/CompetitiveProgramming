#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MOD = 1e9 + 7 ;
#define pb push_back
#define all(v) v.begin(),v.end()
vector < vector  < ll > > g ;
pair < ll , ll > lmx[100100],rmx[100100];
ll tab[100100];
ll leftof[101010];
ll rightof[101010];
ll n;
void go()
{
    stack<pair < ll , ll > > s;

    s.push({0,tab[0]});


    for (int i=1; i<n; i++)
    {
        int next = tab[i];

        if (s.empty() == false)
        {

            pair < ll , ll >  element = s.top();
            s.pop();

            while (element.second < next)
            {
                leftof[element.first] = i;
               // cout<<element.first<<" "<<i<<'\n';
                if (s.empty() == true)
                   break;
                element = s.top();
                s.pop();
            }

            if (element.second > next)
                s.push(element);
        }


        s.push({i,next});
    }

    while (s.empty() == false)
    {
        leftof[s.top().first] = -1 ;
        s.pop();
    }




    s.push({n-1,tab[n-1]});


    for (int i=n-2; i>=0;i--)
    {
        int next = tab[i];

        if (s.empty() == false)
        {

            pair < ll , ll >  element = s.top();
            s.pop();

            while (element.second < next)
            {
                rightof[element.first] = i;
                if (s.empty() == true)
                   break;
                element = s.top();
                s.pop();
            }

            if (element.second > next)
                s.push(element);
        }


        s.push({i,next});
    }

    while (s.empty() == false)
    {
        rightof[s.top().first] = -1 ;
        s.pop();
    }
}
signed main()
{
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    freopen("girls.in", "r", stdin);
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    ll ans =  0  ,T,m ;

    cin>>T ;
    while(T--)
    {

    cin>>n;
    ll mx = -1 ;
    for(int i=0;i<n;i++) cin>>tab[i],leftof[i]=-1,rightof[i]=-1;
    vector < ll > answ ;
    answ.clear(); answ.pb(1);

    go();
    int i = 0 ;
    while(rightof[i]!=-1 || leftof[i]!=-1)
    {

        if(rightof[i]!=-1 && leftof[i]!=-1)
        {

        if(tab[rightof[i]]>=tab[leftof[i]])
        {
            answ.pb(rightof[i]+1);
            i=rightof[i];


        }
        else
        {
        answ.pb(leftof[i]+1);
            i=leftof[i];
        }
        continue ;
        }

        if(rightof[i]!=-1)
        {
        answ.pb(rightof[i]+1);
            i=rightof[i];
            continue ;


        }

        answ.pb(leftof[i]+1);
            i=leftof[i];

    }


    for(int i = 0 ;i<answ.size()-1;i++) cout<< answ[i]<<" ";
    cout<<answ[answ.size()-1]<<'\n';

    }



return 0 ;
}
