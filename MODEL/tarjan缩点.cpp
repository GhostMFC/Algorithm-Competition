#include <bits/stdc++.h>
using namespace std;

const int N=1e4+5;
const int maxm=1e5+5;

int n,m,a[N],cnt,head[N];
struct Edge{
	int fo,to,nxt;
}edge[maxm];
inline void Add(int fo,int to){
	edge[++cnt]={fo,to,head[fo]};
	head[fo]=cnt;
}

bool ins[N];
int dfn[N],low[N],s[N],top,belong[N],gp,v[N];
inline void tj(int x){
	dfn[x]=low[x]=++cnt,s[++top]=x,ins[x]=true;
	for(int i=head[x];i;i=edge[i].nxt){
		int &to=edge[i].to;
		if(!dfn[to]){
			tj(to);
			low[x]=min(low[x],low[to]);
		} else if(ins[to]) low[x]=min(low[x],low[to]);
	}
	
	if(dfn[x]==low[x]){
		int c; ++gp;
		do{
			c=s[top--];
			ins[c]=false;
			belong[c]=gp;
			v[gp]+=a[c];
		} while(top&&c^x);
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	int fo,to;
	for(int i=1;i<=m;++i){
		cin>>fo>>to;
		Add(fo,to);
	}
	
	cnt=0;
	for(int i=1;i<=n;++i)
		if(!dfn[i]){
			top=0;
			tj(i);
		}
		
	cnt=0;
	memset(head,0,sizeof(head));
	for(int i=1;i<=m;++i){
		int x=belong[edge[i].fo],y=belong[edge[i].to];
		if(x^y)
			Add(x,y);
	}
	
	return 0;
}
/*
2 2
1 1
1 2
2 1

2
*/