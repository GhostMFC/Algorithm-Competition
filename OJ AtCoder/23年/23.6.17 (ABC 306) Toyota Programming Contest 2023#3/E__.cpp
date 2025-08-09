#include <bits/stdc++.h>
#define ll long long
#define Mod 998244353
#define Mod1 10000000000037
#define ls node[x].lch
#define rs node[x].rch
#define inf 0x7fffffff
#define inf1 1000000009
#define ull unsigned long long
#define llinf 0x7fffffffffffffff
#define llinf1 1000000000000000009
#define IOS ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define F(a,b,c,d) for(int b=c;b<=d;b+=a)
#define F2(a,b,c,d) for(int b=c;b>=d;b-=a)
#define PRC(b,a) fixed<<setprecision(a)<<b
using namespace std;
using namespace __gnu_cxx;
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
inline ll lowbit(ll xx){return xx&(-xx);}
inline ll Gcd(ll xx,ll yy){return yy?Gcd(yy,xx%yy):xx;}
inline ll q_Mul(ll xx,ll yy,ll pp){ll oo=0;while(yy){if(yy&1)oo=(oo+xx)%pp;xx=(xx<<1)%pp;yy>>=1;}return oo;}
inline ll q_Pow(ll xx,ll yy,ll pp){ll oo=1;for(;yy;yy>>=1,xx=xx*xx%pp)yy&1?oo=oo*xx%pp:0;return oo;}
//q_Pow can conbine with q_Mul to avoid overflow
template <typename T> inline T Min(T xx,T yy){return xx<yy?xx:yy;}
template <typename T> inline T Max(T xx,T yy){return xx>yy?xx:yy;}//(XX-YY>>63)?.:.;

template <typename T1,typename...T2>
inline void read(T1 &x,T2& ...y){read(x);read(y...);}

#define All(x) x.begin(),x.end()

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int d2x[8]={1,0,-1,0,1,-1,-1,1},d2y[8]={0,1,0,-1,1,1,-1,-1};

const int N=500010;

/*
ll ans=0;
int n,a[N],k,q;

int p[N],tmm[N];
priority_queue<pair<int,pair<int,int>>> pq;
priority_queue<pair<int,int>> pm;
map<int,int> mp,tag;

signed main(){
  //freopen();
  //freopen();
  IOS
  //int T;
  cin>>n>>k>>q;
  for(int i=1;i<=k;++i)
    p[i]=0,mp[i]=i,pm.push({0,i}),tag[i]=1;

  while(q--){
    int x,y;
    cin>>x>>y;
    if(mp[x]){
//			cout<<mp[x]<<'\n';
      ans-=p[mp[x]],p[mp[x]]=0;
      tag[x]=0;
      int t=mp[x]; mp[x]=0;
      pq.push({y,{x,++tmm[x]}});
      
      int pp=0,qq;
      while(pq.size()){
        if(pq.top().second.second!=tmm[(int)pq.top().second.first])
          pq.pop();
        else{
          pp=pq.top().second.first,qq=pq.top().first;
          pq.pop();
          break;
        }
      }
      if(pp) p[t]=qq,mp[pp]=k,ans+=qq;
    }
    else{
      pq.push({y,{x,++tmm[x]}});
      while(pm.size()){
      	if(tag[pm.top().second])
      		break;
      	else pm.pop();
			}
      if(-pm.top().first<pq.top().first){
        int t=mp[pm.top().second];
        ans-=p[t],p[t]=0;
        pq.push({pm.top().first,{pm.top().second,++tmm[pm.top().second]}});
        mp[pm.top().second]=0,tag[pm.top().second]=0,pm.pop();

        while(pq.size()){
          if(pq.top().second.second==tmm[(int)pq.top().second.first]){
            pm.push({-pq.top().first,pq.top().second.first});
            tag[pq.top().second.first]=1;
            mp[pq.top().second.first]=t;
            p[t]=pq.top().first;
            pq.pop();
            ans+=p[t];
            break;
          }
          pq.pop();
        }
      }
    }
    cout<<ans<<'\n';
  }
  
  return 0;
}
4 2 10
1 5
2 1
3 3
4 2
2 10
1 0
4 0
3 1
2 0
3 0

*/

ll s;
int k;
multiset<int> x,y;

inline void balance(){
  while(x.size()<k&&y.size()){
    auto iy=y.end();
    --iy;
    x.insert((*iy));
    s+=(*iy);
    y.erase(iy);
  }
  if(x.empty()||y.empty())
    return ;
  
  while(true){
    auto ix=x.begin();
    auto iy=y.end(); --iy;
    int vx=(*ix),vy=(*iy);
    if(vx>=vy) break;
    s+=(vy-vx);
    x.erase(ix),y.erase(iy);
    x.insert(vy),y.insert(vx);
  }
}

inline void add(int v){
  y.insert(v);
  balance();
}

inline void erase(int v){
  auto ix=x.find(v);
  if(ix!=x.end()) s-=v,x.erase(ix);
  else y.erase(y.find(v));
  balance();
}

signed main(){
  IOS
  int n,q;
  cin>>n>>k>>q;
  vector<int> a(n,0);
  for(int i=0;i<k;++i) x.insert(0);
  for(int i=k;i<n;++i) y.insert(0);
  s=0;

  while(q--){
    int d,e;
    cin>>d>>e;
    --d;
    erase(a[d]);
    add(e);
    a[d]=e;
    cout<<s<<'\n';
  }
  return 0;
}
