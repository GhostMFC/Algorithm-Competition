#include <bits/stdc++.h>
#include <bits/extc++.h>
#define Mod 998244353
#define Mod1 10000000000037
#define ls node[x].lch
#define rs node[x].rch
#define inf 0x7fffffff
#define inf1 1000000009
#define llinf 0x7fffffffffffffff
#define llinf1 1000000000000000009
#define IOS ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define F(a,b,c,d) for(int b=c;b<=d;b+=a)
#define F2(a,b,c,d) for(int b=c;b>=d;b-=a)
#define PRC(b,a) fixed<<setprecision(a)<<b
#define Next(a,b) for(int a=head[b];a;a=edge[a].nxt)
using namespace std;
using namespace __gnu_cxx;//rope<T> x
typedef pair<int,int> PII;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> inline void read(T &xx){
  char cc=getchar();T ff=1; xx=0;
  while(cc>'9'||cc<'0'){ ff=cc=='-'?-1:ff,cc=getchar();}
  while(cc<='9'&&cc>='0'){ xx=(xx<<1)+(xx<<3)+(cc^48),cc=getchar();}
  xx=xx*ff;
}
template <typename T> inline void write(T xx){
  if(xx<0){ putchar('-'),xx=-xx;}
  if(xx>9) write(xx/10);
  putchar(xx%10+'0');
}
inline ll q_2(ll xx){return xx*xx;}
inline ll lowbit(ll xx){return xx&(-xx);}
inline ll Gcd(ll xx,ll yy){return yy?Gcd(yy,xx%yy):xx;}
inline ll q_Mul(ll xx,ll yy,ll pp){ll oo=0;while(yy){if(yy&1)oo=(oo+xx)%pp;xx=(xx<<1)%pp;yy>>=1;}return oo;}
inline ll q_Pow(ll xx,ll yy,ll pp){ll oo=1;for(;yy;yy>>=1,xx=xx*xx%pp)yy&1?oo=oo*xx%pp:0;return oo;}
//q_Pow can conbine with q_Mul to avoid overflow
template <typename T> inline T Min(T xx,T yy){return xx<yy?xx:yy;}
template <typename T> inline T Max(T xx,T yy){return xx>yy?xx:yy;}//(XX-YY>>63)?.:.;
template <typename T> inline void sMin(T &xx,T yy){xx=(xx<yy)?xx:yy;}
template <typename T> inline void sMax(T &xx,T yy){xx=(xx>yy)?xx:yy;}

template <typename T1,typename...T2>
inline void read(T1 &x,T2& ...y){read(x);read(y...);}
inline void Cout(){cout<<endl;}
template <class T1,class...T2>
inline void Cout(T1 x,T2 ...y){cout<<x<<' ';Cout(y...);}

#define pb push_back
#define All(x) x.begin(),x.end()

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int d2x[8]={1,0,-1,0,1,-1,-1,1},d2y[8]={0,1,0,-1,1,1,-1,-1};

const double PI=acos(-1),eps=1e-10;

const int N=100010,mod=998244353;

int n,m;

inline ll inv(ll x){ return q_Pow(x,mod-2,mod);}

signed main(){
  //freopen();
  //freopen();
  srand(time(0));
  IOS
  //int T;
  int n;
  cin>>n;
  unordered_map<int,vector<pair<int, int>>> vmp;
  set<int> st;

  for(int i=0;i<n;++i){
    unordered_map<int, int> freq;
    for(int j=0;j<6;++j){
      int num;
      cin>>num;
      ++freq[num];
    }
    for(auto &p:freq){
      int val=p.first;
      int cnt=p.second;
      vmp[val].push_back({i,cnt});
      st.insert(val);
    }
  }

  if(st.empty()) return cout<<0<<'\n',0;

  vector<int> dv(st.begin(),st.end());//distinct vals
  sort(All(dv));
  int sz=dv.size();

  vector<ll> c(n,0);
  ll np=1,S=0;//p is none 0 product
  int zeros=n;

  for (int i=0;i<sz-1;++i) {
    int v=dv[i];
    auto it=vmp.find(v);
    if(it==vmp.end()) continue;
    vector<PII>& list=it->second;//
    for (auto p:list) {
      int i=p.first;
      int cv=p.second;
      long long old_count=c[i];
      long long new_count=old_count+cv;
      c[i]=new_count;

      if(!old_count){
        --zeros;
        (np*=new_count)%=mod;
      } else{
        (np*=inv(old_count))%=mod;
        (np*=new_count)%=mod;
      }
    }

    ll P=(!zeros)?np:0;
    ll gap=dv[i+1]-dv[i];
    gap%=mod;
    if(gap<0) gap+=mod;
    (S+=gap*P)%mod;
  }

  ll totp=q_Pow(6ll,n,mod);
  ll v = dv.back();
  ll numerator=(totp*(v%mod)%mod-S)%mod;
  if(numerator<0) numerator+=mod;
  ll result=numerator*inv(totp)%mod;
  cout<<result<<'\n';
  
  return 0;
}