#include <bits/stdc++.h>
using namespace std;

struct BigInt{
//	const static int MOD=10;//进制 
//	const static int DLEN=1; 
	int a[1001],len;
	void Init(){
		memset(a,0,sizeof(a));
		len=1;
	}
	void Assign_Int(long long v){//常数赋值 
		memset(a,0,sizeof(a));
		len=0;
		do{
			a[++len]=v%10;
			v/=10;
		}while(v);
	}
	void Assign_BigInt(char s[]){//字符串赋值 
		memset(a,0,sizeof(a));
		len=strlen(s+1);
		for(int i=len;i;--i)
			a[len-i+1]=s[i]-'0';
	}
	BigInt operator +(const BigInt &b)const{
		BigInt res;
		res.len=max(len,b.len);
		for(int i=res.len+1;i;--i)
			res.a[i]=0;
		for(int i=1;i<=res.len;++i){
			res.a[i]+=((i<=len)?a[i]:0)+((i<=b.len)?b.a[i]:0);
			res.a[i+1]+=res.a[i]/10,res.a[i]%=10;
		} if(res.a[res.len+1]) ++res.len;
		return res;
	}
	BigInt operator *(const BigInt &b)const{
		BigInt res;
		for(int i=len+b.len;i;--i) res.a[i]=0;
		for(int i=1;i<=len;++i){
			int up=0;
			for(int j=1;j<=b.len;++j){
				int tmp=a[i]*b.a[j]+res.a[i+j-1]+up;
				res.a[i+j-1]=tmp%10,up=tmp/10;
			} if(up) res.a[i+b.len]+=up;
		} res.len=len+b.len;
		while(!res.a[res.len]&&res.len>1) --res.len;
		return res;
	}
	bool operator <(const BigInt &b)const{
		if(len>b.len) return false;
		if(len<b.len) return true;
		for(int i=len;i;--i)
			if(a[i]>b.a[i]) return false;
			else if(a[i]<b.a[i]) return true;
		return false;
	}
	void Print(){
		for(int i=len;i;--i)
			printf("%d",a[i]);
	}
	void Cout(){
		for(int i=len;i;--i)
			cout<<a[i];
		cout<<'\n';
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	BigInt A,B;
	A.Assign_Int(1),B.Assign_Int(99);
	A=A+B;
	A.Cout(); 
	return 0;
}
 
