#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline void exgcd(ll a,ll b,ll& d,ll& x,ll& y){
  if(!b){ d=a,x=1,y=0;}
  else{ exgcd(b,a%b,d,y,x); y-=x*(a/b);}
}

inline ll CRT(int n,int* a,int* m){
  ll M=1,d,y,x=0;
  for(int i=1;i<=n;++i) M*=m[i];
  for(int i=1;i<=n;++i){
    ll w=M/m[i];
    exgcd(m[i],w,d,d,y);
    x=(x+y*w*a[i])%M;
  }
  return (x+M)%M;
}

int n,a[15],b[15];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);

  cin>>n;
  for(int i=1;i<=n;++i)
    cin>>a[i]>>b[i];

  cout<<CRT(n,b,a)<<'\n';
  return 0;
}