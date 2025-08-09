#include <bits/stdc++.h> 
#define ll long long
#define F(a,b,c,d) for(int b=c;b<=d;b+=a)
#define F2(a,b,c,d) for(int b=c;b>=d;b-=a)
using namespace std;

const int maxn=200;

int n,m;
bool vis[maxn][maxn];

int main(){//cin_data
	srand(time(0));
	
	freopen("portal3.in","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	n=200,m=33;
	cout<<n<<' '<<m<<'\n';
	
	F(1,i,1,n-1){
		while(true){
			int x,y,z;
			x=rand()%n+1,y=rand()%n+1,z=rand()%200+1;
			if(x==y||vis[x][y]||vis[y][x]) continue;
			vis[x][y]=true;
			cout<<x<<' '<<y<<' '<<z<<'\n';
			break;
		}
	}
	
	memset(vis,0,sizeof(vis));
	
	F(1,i,1,m){
		while(true){
			int x=rand()%n+1,y=rand()%n+1;
			if(x==y||vis[x][y]||vis[y][x]) continue;
			vis[x][y]=true;
			cout<<x<<' '<<y<<'\n';
			break;
		}
	}
	
	int x=rand()%n+1;
	if(x==1) x=n;
	cout<<x;
	return 0;
}

