#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=200010;

int n,m,cnt,head[N];
struct Edge{int fo,to,nxt,val;}edge[N<<1];
inline void Add(int fo,int to,int val){
  edge[++cnt]={fo,to,head[fo],val};
  head[fo]=cnt;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  
  return 0;
}