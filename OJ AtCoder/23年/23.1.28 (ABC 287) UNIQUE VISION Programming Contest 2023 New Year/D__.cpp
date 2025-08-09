#include <bits/stdc++.h>
using namespace std;

const int N=300010;

int sl,tl;
char s[N],t[N];
bool pre[N],suf[N];

inline bool check(int x,int y)
{return (s[x]=='?'||t[y]=='?'||s[x]==t[y])?true:false;}

signed main(){
  cin>>s+1>>t+1;

  sl=strlen(s+1),tl=strlen(t+1);

  pre[0]=suf[0]=true;
  for(int i=1;i<=tl;++i){
    pre[i]=pre[i-1]&check(i,i);
    suf[i]=suf[i-1]&check(sl-i+1,tl-i+1);
  }

  for(int i=0;i<=tl;++i)
    cout<<((pre[i]&suf[tl-i])?"Yes":"No")<<'\n';
  return 0;
}