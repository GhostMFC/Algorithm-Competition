#include <bits/stdc++.h>
using namespace std;

const int maxn=100005;
int a[maxn],n;

inline void Sort(int l,int r){
	int mid=a[(l+r)>>1],i=l,j=r;
	while(i<=j){
		while(a[i]<mid) ++i;
		while(a[j]>mid) --j;
		if(i<=j){
			if(i^j) a[i]^=a[j]^=a[i]^=a[j];
			++i,--j;
		}
	}
	if(l<j) Sort(l,j);
	if(i<r) Sort(i,r);
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	random_shuffle(a+1,a+1+n);
	Sort(1,n);
	for(int i=1;i<n;++i)
		cout<<a[i]<<' ';
	cout<<a[n]<<'\n';
	return 0;
} 
