#include <bits/stdc++.h>
#define pb(a) push_back(a)
using namespace std;

const int N=1000010;

int n,m;
vector<int> G[N<<1];
bool mark[N<<1];
int s[N<<1],c;

inline void init(int n){
  for(int i=0;i<(n<<1);++i) G[i].clear();
  memset(mark,0,sizeof(mark));
}

inline void Add(int x,int xval,int y,int yval){
  x=(x<<1)+xval,y=(y<<1)+yval;
  G[x^1].pb(y),G[y^1].pb(x);
}

inline bool dfs(int pos){
  if(mark[pos^1]) return false;
  if(mark[pos]) return true;
  mark[pos]=true;
  s[c++]=pos;
  for(int to:G[pos])
    if(!dfs(to)) return false;
  return true;
}

inline bool solve(){
  for(int i=0;i<(n<<1);i+=2)
    if(!mark[i]&&!mark[i+1]){
      c=0;
      if(!dfs(i)){
        while(c>0) mark[s[--c]]=false;
        if(!dfs(i+1)) return false;
      }
    }
  return true;
}

// struct TwoSAT{
//   int n;
//   vector<int> G[N<<1];
//   bool mark[N<<1];
//   int s[N<<1],c;

//   inline void init(int n){
//     this->n=n;
//     for(int i=0;i<(n<<1);++i) G[i].clear();
//     memset(mark,0,sizeof(mark));
//   }

//   inline void Add(int x,int xval,int y,int yval){
//     x=(x<<1)+xval,y=(y<<1)+yval;
//     G[x^1].pb(y),G[y^1].pb(x);
//   }

//   inline bool dfs(int pos){
//     if(mark[pos^1]) return false;
//     if(mark[pos]) return true;
//     mark[pos]=true;
//     s[c++]=pos;
//     for(int to:G[pos])
//       if(!dfs(to)) return false;
//     return true;
//   }

//   inline bool solve(){
//     for(int i=0;i<(n<<1);i+=2)
//       if(!mark[i]&&!mark[i+1]){
//         c=0;
//         if(!dfs(i)){
//           while(c>0) mark[s[--c]]=false;
//           if(!dfs(i+1)) return false;
//         }
//       }
//     return true;
//   }
// };

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);

  cin>>n>>m;
  // TwoSAT ans; ans.init(n);
  init(n);
  for(int i=1;i<=m;++i){
    int x,xval,y,yval;
    cin>>x>>xval>>y>>yval;
    Add(x,xval,y,yval);
  }
  if(solve()){
    cout<<"POSSIBLE\n";
    for(int i=2;i<=(n<<1);i+=2){
      if(mark[i]) cout<<0<<' ';
      else cout<<1<<' ';
    } cout<<'\n';
  } else cout<<"IMPOSSIBLE\n";

  return 0;
}