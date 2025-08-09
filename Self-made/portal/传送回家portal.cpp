#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <queue>
#define ll long long
#define F(a,b,c,d) for(int b=c;b<=d;b+=a)
#define F2(a,b,c,d) for(int b=c;b>=d;b-=a)
#define INF 1000000007
using namespace std;

const int maxn=3e4+5;

int n,m,pos;
int d[maxn];
bool vis[maxn];

struct Edge{
	int to,nxt,val;
}edge[maxn*3];

struct Node{int num,w;}h;

inline bool operator<(const Node A,const Node B)
{ return A.w>B.w;}

int cnt,head[maxn];
inline void Add_(int fo,int to,int val){
	edge[++cnt]={to,head[fo],val};
	head[fo]=cnt;
}

priority_queue <Node> pq;
inline void Dij(){
	fill(d+1,d+1+n,INF);
	d[pos]=0,h={pos,0};
	pq.push(h);
	F(1,j,1,n-1){
		h=pq.top(); pq.pop();
		if(vis[h.num]){ --j; continue;}
		vis[h.num]=true;
		int fo=h.num;
		for(int i=head[h.num];i;i=edge[i].nxt){
			int to=edge[i].to,val=edge[i].val;
			if(d[to]>d[fo]+val){
				d[to]=d[fo]+val;
				pq.push({to,d[to]});
			}
		}
	}
}

int main(){
	freopen("portal3.in","r",stdin);
//	freopen("portal3.ans","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	int fo,to,val;
	F(1,i,1,n-1){
		cin>>fo>>to>>val;
		Add_(fo,to,val);
		Add_(to,fo,val);
	}
	F(1,i,1,m){
		cin>>fo>>to;
		Add_(fo,to,1);
		Add_(to,fo,1);
	}
	cin>>pos;
	Dij();
	cout<<d[1]<<'\n';
	return 0;
}
/*
6 0
1 2 1
2 3 114
3 4 196
4 5 144
5 6 16
5

455
*/ 
