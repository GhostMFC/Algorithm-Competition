#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline ll q_Pow(ll xx,ll yy,ll pp){ll oo=1;for(;yy;yy>>=1,xx=xx*xx%pp)yy&1?oo=oo*xx%pp:0;return oo;}

inline int BSGS(int a,int b,int n){
  ll m,v,e=1,i;
  m=(int)sqrt(n+0.5);
  v=q_Pow(q_Pow(a,m,n),n-2,n);//(a^m)^(-1)
  unordered_map<int,int> x;
  x[1]=0;
  for(int i=1;i<m;++i){
    e=e*a%n;
    if(!x.count(e)) x[e]=i;
  }
  for(int i=0;i<m;++i){//考虑a^(im),a^(im+1)...a^(im+m-1)
    if(x.count(b)) return i*m+x[b];
    b=b*v%n;
  }
  return -1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  int a,b,n;
  cin>>a>>b>>n;//a^x (=) b (mod n)
  int k=BSGS(a,b,n);
  if(k==-1) cout<<"no solution\n";
  else cout<<k<<'\n';

  return 0;
}