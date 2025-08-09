#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int N=2000010;
 
int n,m;
 
inline int lowbit(int x){return x&-x;}
 
struct Fenwick_Tree{//BIT_Max_Value
  int lenth;
  ll tr[N],p[N];
  inline void init(){
    lenth=n;
    memset(tr,0,sizeof(tr));
    memset(p,0,sizeof(p));
  }
  inline void update(int x,ll v)
  {p[x]=max(p[x],v);while(x<=lenth) tr[x]=max(tr[x],v),x+=lowbit(x);}
  inline ll query(int l,int r){
    ll res=-1e18;
    while(l<=r){
      res=max(res,p[r]),--r;
      while(r-lowbit(r)>=l){
        res=max(res,tr[r]);
        r-=lowbit(r);
      }
    }
    return res;
  }
}bit;
 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
   
  cin>>n>>m;
  bit.init();
 
  for(int i=1,x;i<=n;++i){
    cin>>x;
    bit.update(i,x);
  }
 
  int l,r;
  while(m--){
    cin>>l>>r;
    cout<<bit.query(l,r)<<'\n';
  }
   
  return 0;
}