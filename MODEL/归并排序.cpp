#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1000000+10;
long long A[maxn],T[maxn];
int n;

void merge_sort(int l,int r){
	if(r!=l){
		int mid=(l+r)>>1;
		int p=l,q=mid+1,i=l;
		merge_sort(l,mid);
		merge_sort(mid+1,r);
		while(p<=mid||q<=r){
			if(q>r||(p<=mid&&A[p]<=A[q])) T[i++]=A[p++];
			else T[i++]=A[q++];
		}
		for(i=l;i<=r;i++) A[i]=T[i];
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&A[i]);
	merge_sort(1,n);
	for(int i=1;i<=n;i++) printf("%lld ",A[i]);
	return 0;
}
