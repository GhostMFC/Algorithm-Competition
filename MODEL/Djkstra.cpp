#include <bits/stdc++.h>
using namespace std;

const int N=200010;

int n,m,head[N],cnt;
struct Edge{int fo,to,nxt,val;}edge[N];
struct Node{int num,val;};
bool operator<(Node a,Node b){ return a.val>b.val;}
priority_queue<Node> pq;
inline void Dijkstra(){
	Node k={ori,0};
	pq.push(k);
	F(1,i,1,n-1){
		k=pq.top();
		pq.pop();
		if(vis[k.num]==true){ --i;continue;}
		vis[k.num]=true;
		int fo=k.num;
		for(int i=head[k.num];i;i=edge[i].nxt){
			int to=edge[i].to,val=edge[i].val;
			if(d[to]>d[fo]+val){
				d[to]=d[fo]+val;
				k={to,d[to]};
				pq.push(k);
			}
		}
	}
}

int main(){

  return 0;
}