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

const int N=500010;

int n,q;
string s;

int cnt;
struct Node{
  int l,r,lch,rch;
  char lc,rc;
  int size,pre,suf,mx;
}node[N<<1];

Node merge(Node L, Node R) {
  Node res;
  res.lc=L.lc;
  res.rc=R.rc;
  res.size=L.size+R.size;
  res.pre=L.pre;
  if(L.pre==L.size&&L.rc==R.lc) 
    res.pre=L.pre+R.pre;
  res.suf=R.suf;
  if (R.suf==R.size&&R.lc==L.rc) 
    res.suf=R.suf+L.suf;
  res.mx=max(L.mx,R.mx);
  if(L.rc==R.lc) 
    res.mx=max(res.mx,L.suf+R.pre);
  return res;
}

void push_up(int x) {
  node[x].lc=node[ls].lc;
  node[x].rc=node[rs].rc;
  node[x].size=node[ls].size+node[rs].size;
  node[x].pre=node[ls].pre;
  if(node[ls].pre==node[ls].size&&node[ls].rc==node[rs].lc)
    node[x].pre=node[ls].pre+node[rs].pre;
  node[x].suf=node[rs].suf;
  if(node[rs].suf==node[rs].size&&node[rs].lc==node[ls].rc)
    node[x].suf=node[rs].suf+node[ls].suf;
  node[x].mx=max(node[ls].mx,node[rs].mx);
  if(node[ls].rc==node[rs].lc)
    node[x].mx=max(node[x].mx,node[ls].suf+node[rs].pre);
}

int build(int l,int r) {
  int x=++cnt;
  node[x].l=l,node[x].r=r;
  if(l==r){
    node[x].lc=node[x].rc=s[l-1]; //l
    node[x].size=1;
    node[x].pre=node[x].suf=node[x].mx=1;
    return x;
  }
  int mid=(l+r)>>1;
  ls=build(l,mid);
  rs=build(mid+1,r);
  push_up(x);
  return x;
}

void update(int x,int pos,char c) {
  if(node[x].l==node[x].r){
    node[x].lc=node[x].rc=c;
    return;
  }
  int mid=(node[x].l+node[x].r)>>1;
  if(pos<=mid) update(ls,pos,c);
  else update(rs,pos,c);
  push_up(x);
}

Node query(int x,int ql,int qr) {
  if(ql<=node[x].l&&node[x].r<=qr)
    return node[x];
  int mid=(node[x].l+node[x].r)>>1;
  if(qr<=mid) return query(ls,ql,qr);
  if(ql>mid) return query(rs,ql,qr);
  Node L=query(ls,ql,mid);
  Node R=query(rs,mid+1,qr);
  return merge(L,R);
}

int main() {
  IOS
  cin>>n>>q;
  cin>>s;
  build(1,n);
  while(q--){
    int op;
    cin>>op;
    if(op==1){
      int pos;
      char c;
      cin>>pos>>c;
      update(1,pos,c);
    } else {
      int l,r;
      cin>>l>>r;
      cout<<query(1,l,r).mx<<'\n';
    }
  }
  return 0;
}