#include <bits/stdc++.h>
using namespace std;
int n[1111],m,p,ln,i,j,mx;
struct matrix{
	int n,m,a[35][35];
	void init(){
		n=0;
		m=0;
		memset(a,0,sizeof(a));
	}
	matrix operator * (const matrix &aa)const{
		matrix b;
		b.init();
		b.n=n;
		b.m=aa.m;
		for(int i=0;i<n;i++)
		for(int j=0;j<aa.m;j++)
		for(int k=0;k<m;k++){
			b.a[i][j]=(b.a[i][j]+a[i][k]*aa.a[k][j])%p;
		}
		return b;
	}
}base,ans;

char s[1111];

int check(int x,int y)
{
	int a[7],ca=0;
	int b[7],cb=0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	while(x){
		a[ca]=x&1;
		x>>=1;
		ca++;
	}
	while(y){
		b[cb]=y&1;
		y>>=1;
		cb++;
	}
	for(int i=0;i<m-1;i++){
		if(a[i]==b[i] && a[i+1]==b[i+1] && a[i]==a[i+1])return 0;
	}
	return 1;
}

int main()
{
	freopen("test.in","r",stdin);
	// freopen("nice.in","r",stdin);
	// freopen("nice.out","w",stdout);
	scanf("%s",s);
	scanf("%d%d",&m,&p);
	ln=(int)strlen(s);
	for(i=0;i<ln;i++){
		n[ln-i]=s[i]-'0';
	}
	mx=1<<m;
	base.init();
	ans.init();
	base.n=base.m=mx;
	ans.n=1;
	ans.m=mx;
	for(i=0;i<mx;i++){
		ans.a[0][i]=1;
	}
	for(i=0;i<mx;i++)
	for(j=0;j<mx;j++){
		base.a[i][j]=check(i,j);
	}
	n[1]--;
	i=1;
	while(n[i]<0){
		n[i+1]--;
		n[i]+=10;
		i++;
	}
	if(n[ln]==0)ln--;
	while(ln){
		if(n[1]&1){
			ans=ans*base;
		}
		base=base*base;
		for(i=ln;i>=1;i--)
		{
			n[i-1]+=(n[i]&1)*10;
			n[i]>>=1;
		}
		n[0]=0;
		if(n[ln]==0)ln--;
		for(i=ln;i>=1;i--)
		{
			cout << n[i];
		}
        cout << '\n';
	}
	int anss=0;
	for(int i=0;i<mx;i++)anss=(anss+ans.a[0][i])%p;
	printf("%d\n",anss);
}