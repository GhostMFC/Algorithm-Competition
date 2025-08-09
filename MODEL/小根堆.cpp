#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define MAXN 1000010
using namespace std;

int n;
struct Pri{
	int a[MAXN];
	int cnt;
	void Insert(int x){
		a[++cnt]=x;
		int p=cnt;
		while(a[p]<a[p/2]&&p/2>0){
			swap(a[p],a[p/2]);
			p/=2;
		}
	}
	void Pop(){
		swap(a[1],a[cnt]);
		--cnt;
		int p=1;
		int k=p;
		while(true){
			if(p*2<=cnt)
				if(a[p*2]<a[k])
					k=p*2;
			if(p*2+1<=cnt)
				if(a[p*2+1]<a[k])
					k=p*2+1;
			if(k==p) break;
			swap(a[p],a[k]);
			p=k;
		}
	}
}pq;

int main(){
	std::ios::sync_with_stdio(false);
	cin>>n;
	int x,y;
	while(n--){
		cin>>x;
		if(x==1){
			cin>>y;
			pq.Insert(y);
		}
		else if(x==2){
			cout<<pq.a[1]<<endl;
		}
		else if(x==3)
			pq.Pop();
	}
	return 0;
}
