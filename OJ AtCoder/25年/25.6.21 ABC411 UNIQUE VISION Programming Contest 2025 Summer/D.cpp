#include <bits/stdc++.h>
#define inf 0x7fffffff
#define llinf 0x7fffffffffffffff
#define F(a,b,c,d) for(int b=c;b<=d;b+=a)
#define F2(a,b,c,d) for(int b=c;b>=d;b-=a)
#define PRC(b,a) fixed<<setprecision(a)<<b
#define pb push_back
#define All(x) x.begin(),x.end()
#define Next(a,b) for(int a=head[b];a;a=edge[a].nxt)
#define IOS ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef unsigned long long ull;
inline ll q_2(ll xx){return xx*xx;}
inline ll Gcd(ll xx,ll yy){return yy?Gcd(yy,xx%yy):xx;}
inline ll q_Pow(ll xx,ll yy,ll pp){ll oo=1;for(;yy;yy>>=1,xx=xx*xx%pp)yy&1?oo=oo*xx%pp:0;return oo;}
inline void Cout(){cout<<endl;}
template <class T1,class...T2>
inline void Cout(T1 x,T2 ...y){cout<<x<<' ';Cout(y...);}
template <typename T> inline void sMin(T &xx,T yy){xx=(xx<yy)?xx:yy;}
template <typename T> inline void sMax(T &xx,T yy){xx=(xx>yy)?xx:yy;}

const int N=200010;

int n;
string s[N],server;

signed main(){
  IOS
  int T;
  cin>>n>>T;
  vector<pair<int, string>> nodes;
  nodes.pb({-1,""}); // node0: root
  vector<int> pc_indices(n,0);
  int server_index=0;

  while(T--){
    int opt,p;
    string t;
    cin>>opt;
    if(opt==1){
      cin>>p;
      pc_indices[--p]=server_index;
    } else if(opt==2){
      cin>>p>>t;
      nodes.pb({pc_indices[--p],t});
      pc_indices[p]=nodes.size()-1;
    } else{
      cin>>p;
      server_index=pc_indices[--p];
    }
  }

  vector<int> chain;
  int cur=server_index;
  ll len=0;
  while (cur!=-1) {
    chain.push_back(cur);
    len+=nodes[cur].second.size();
    cur=nodes[cur].first;
  }
  string ans="";
  ans.reserve(len);
  reverse(chain.begin(),chain.end());
  for(auto o:chain)
    ans+=nodes[o].second;
  cout<<ans<<'\n';

  return 0;
}