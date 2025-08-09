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

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int d2x[8]={1,0,-1,0,1,-1,-1,1},d2y[8]={0,1,0,-1,1,1,-1,-1};

int tot[3000010];
bool vis[3000010];
inline void _1_get_prime(){
	int l,r; vis[1]=vis[0]=true;
	scanf("%d %d",&l,&r);
	if(!vis[4]){
		for(int i=2;i<=r;++i){
			if(!vis[i]){
				tot[i]=1;
				for(int k=i+i;k<=r;k+=i)
					vis[k]=true;
			} tot[i]+=tot[i-1];
		}
	}
	
	if(l<=0) l=1;
	printf("%d primes: ",tot[r]-tot[l-1]);
	if(tot[r]-tot[l-1]>100){
		printf("Too many primes!!!\n");
		return ;
	}
	int tt=0;
	for(int i=l;i<=r;++i){
		if(!vis[i]) printf("Prime #%d: %d ",++tt,i);
		if(tt%5==0) printf("\n");
	}
}

ll kk,gg;
struct MT{ll mp[2][2];}tmppp;
inline MT MT_Times(MT A,MT B){
	MT res;
	res.mp[0][0]=(A.mp[0][0]*B.mp[0][0]+A.mp[0][1]*B.mp[1][0])%gg;
	res.mp[0][1]=(A.mp[0][0]*B.mp[0][1]+A.mp[0][1]*B.mp[1][1])%gg;
	res.mp[1][0]=(A.mp[1][0]*B.mp[0][0]+A.mp[1][1]*B.mp[1][0])%gg;
	res.mp[1][1]=(A.mp[1][0]*B.mp[0][1]+A.mp[1][1]*B.mp[1][1])%gg;
	return res;
}
inline void _2_get_fibonacci(){//1 1 2 3 5...
	scanf("%lld %lld",&kk,&gg); ll p=kk;
	MT mt,res=tmppp;
	mt.mp[0][0]=mt.mp[0][1]=mt.mp[1][0]=1,mt.mp[1][1]=0,
	res.mp[0][0]=res.mp[1][1]=1;
	if(kk<3){printf("The %d'th number is: 1\n",gg); return ;}
	kk-=2;
	while(kk){
		if(kk&1) res=MT_Times(res,mt);
		mt=MT_Times(mt,mt);
		kk>>=1;
	}
	printf("The %d'th number (mod what U put) is: %lld\n",p,(res.mp[0][0]+res.mp[1][1])%gg);
}

inline void _3_get_lcm_gcd(){
	ll A,B;
	scanf("%lld%lld",&A,&B);
	printf("LCM is %lld, GCD is %lld\n",A*B/Gcd(A,B),Gcd(A,B));
}

int tttot[50],ttcnt;
inline void _4_get_divides(){
	ll A;
	scanf("%lld",&A);
	ttcnt=0;
	for(int i=1;i*i<=A;++i)
		if(A%i==0){
			tttot[++ttcnt]=i;
			if(i*i!=A) tttot[++ttcnt]=A/i;
		}
	sort(tttot+1,tttot+1+ttcnt);
	printf("Totally %d divides: ",ttcnt);
	for(int i=1;i<=ttcnt;++i){
		printf("Divides #%d: %d ||| ",i,tttot[i]);
		if(i%5==0) puts("");
	}
}

inline void _5_get_prime_divides(){
	ll A;
	scanf("%lld",&A);
	ttcnt=0;
	for(int i=2;i*i<=A;++i)
		if(A%i==0){
			tttot[++ttcnt]=i;
			while(A%i==0) A/=i;
		}
	if(A^1) tttot[++ttcnt]=A;
	printf("Totally %d prime divides: ",ttcnt);
	for(int i=1;i<=ttcnt;++i){
		printf("P-Divedes #%d: %d |||",i,tttot[i]);
		if(i%5==0) puts("");
	}
}

const int NNN=2000;
int ssumm[NNN<<1],aaa[NNN],lll,www;
void plllll(){//¸ß¾«¼Ó 
	for(int i=1;i<=www;i++){
		ssumm[i]+=aaa[i];
		aaa[i]=0;
		ssumm[i+1]+=ssumm[i]/10,ssumm[i]%=10;
	}
	int k=www+1;
	while(ssumm[k]){
		ssumm[k+1]+=ssumm[k]/10;
		ssumm[k]%=10,++k;
	} lll=Max(lll,k-1);
}

inline void _6_get_factorial(){
	int T;
	cin>>T;
	lll=0;
	memset(ssumm,0,sizeof(ssumm));
	memset(aaa,0,sizeof(aaa));
	www=aaa[1]=1;
	for(register int i=2;i<=T;i++){
		for(register int j=1;j<=www;j++)
			aaa[j]*=i;
		for(register int j=1;j<=www;j++)
			aaa[j+1]+=(aaa[j]/10),aaa[j]%=10;
		while(aaa[www+1]){
			++www;
			aaa[www+1]=aaa[www]/10;
			aaa[www]%=10;
		}
	}
	plllll();
	for(int i=lll;i>=1;i--)
		cout<<ssumm[i];
}

inline void _7_get_A_B_Mod(){
	ll A,B,M;
	cin>>A>>B>>M;
	cout<<q_Pow(A,B,M)<<'\n';
}

inline void Hall(){
	printf("Please give your instructions:\n");
	printf("1-->get the primes during [l,r] (l,r <= 3e6)\n");
	printf("2-->get the k'th number(mod g) in fibonacci(1,1,2,3...) (k <= 1e18,g <= 1e9)\n");
	printf("3-->get lcm and gcd of two numbers A and B (A,B <= 1e9)\n");
	printf("4-->get divides of number A (A <= 1e9)\n");
	printf("5-->get prime divides of number A (A <= 1e9)\n");
	printf("6-->get the factorial of A (A <= 807)\n");
	printf("7-->get the result of A^B(mod M) (A<=1e9,B<=1e9,M<=1e9)\n");
	printf("8-->\n");
	printf("9-->\n");
	printf("10-->\n");
	printf("\n");
	
	int opt;
	scanf("%d",&opt);
	if(opt==1) _1_get_prime();
	else if(opt==2) _2_get_fibonacci();
	else if(opt==3) _3_get_lcm_gcd();
	else if(opt==4) _4_get_divides();
	else if(opt==5) _5_get_prime_divides();
	else if(opt==6) _6_get_factorial();
	else if(opt==7) _7_get_A_B_Mod();
	
	system("pause");
	
	printf("\n");
}

int main(){
//  freopen("tool.in","r",stdin);
//  freopen("tool.out","w",stdout);
  srand(time(0));
  while(true) Hall();
//  system("pause");
  return 0;
}

