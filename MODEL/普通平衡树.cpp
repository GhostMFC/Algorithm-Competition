#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;

const int N=100010,inf=0x7fffffff;

struct Node{
  int ch[2],val,key/*节点,权值*/,cnt,sz;
}node[N];
int tot,root,n;

int New(int val)
{ return node[++tot]={{0,0},val,rand(),1,1},tot;}
void Update(int p)
{ node[p].sz=node[node[p].ch[0]].sz+node[node[p].ch[1]].sz+node[p].cnt;}
void Build()
{ New(inf); root=1; Update(root);}

void Rotate(int &p,int d){//d=1为右旋
  int k=node[p].ch[d^1]; node[p].ch[d^1]=node[k].ch[d],node[k].ch[d]=p;
  Update(p); Update(k); p=k;
}

int GetRankByVal(int p,int val){
  if(!p) return 0;
  if(val==node[p].val) return node[node[p].ch[0]].sz+1;
  if(val<node[p].val) return GetRankByVal(node[p].ch[0],val);
  return GetRankByVal(node[p].ch[1],val)+node[node[p].ch[0]].sz+node[p].cnt;
}

int GetValByRank(int p,int rank){
  if(!p) return inf;
  if(node[node[p].ch[0]].sz>=rank) return GetValByRank(node[p].ch[0],rank);
  if(node[node[p].ch[0]].sz+node[p].cnt>=rank) return node[p].val;
  return GetValByRank(node[p].ch[1],rank-node[node[p].ch[0]].sz-node[p].cnt);
}

void Insert(int &p,int val){
  if(!p) return p=New(val),void();
  if(val==node[p].val) return node[p].cnt++,node[p].sz++,void();
  if(val<node[p].val){
    Insert(node[p].ch[0],val);
    if(node[p].key<node[node[p].ch[0]].key) Rotate(p,1);
  } else{
    Insert(node[p].ch[1],val);
    if(node[p].key<node[node[p].ch[1]].key) Rotate(p,0);
  } Update(p);
}

int GetPre(int p,int val){
  if(!p) return -inf;
  if(val<=node[p].val) return GetPre(node[p].ch[0],val);
  return max(node[p].val,GetPre(node[p].ch[1],val));
}

int GetNext(int p,int val){
  if(!p) return inf;
  if(val>=node[p].val) return GetNext(node[p].ch[1],val);
  return min(node[p].val,GetNext(node[p].ch[0],val));
}

void Remove(int &p,int val){
  if(!p) return;
  if(val==node[p].val){
    if(node[p].cnt>1) return node[p].cnt--,node[p].sz--,void();
    if(node[p].ch[0]||node[p].ch[1]){//不是叶节点
      if(!node[p].ch[1]||node[node[p].ch[0]].key>node[node[p].ch[1]].key)
        Rotate(p,1),Remove(node[p].ch[1],val);
      else
        Rotate(p,0),Remove(node[p].ch[0],val);
      Update(p);
    } else p=0;//删除叶节点(引用)
    return ;
  }
  Remove(val<node[p].val?node[p].ch[0]:node[p].ch[1],val);
  Update(p);
}

int main(){
  IOS
  srand(time(0));
  
  Build();
  cin>>n;
  while(n--){
    int opt,x;
    cin>>opt>>x;
    switch(opt){
      case 1: Insert(root,x); break;
      case 2: Remove(root,x); break;
      case 3: cout<<GetRankByVal(root,x)<<'\n'; break;
      case 4: cout<<GetValByRank(root,x)<<'\n'; break;
      case 5: cout<<GetPre(root,x)<<'\n'; break;
      case 6: cout<<GetNext(root,x)<<'\n'; break;
    }
  }
  return 0;
}