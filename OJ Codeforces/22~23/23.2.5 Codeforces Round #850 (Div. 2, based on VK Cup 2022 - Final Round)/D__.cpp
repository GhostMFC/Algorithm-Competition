#include <bits/stdc++.h>
#define ll long long
#define All(x) x.begin(),x.end()
using namespace std;

const int N=100010;

int m;
struct ANS{int a;char A;int b;char B;};
struct Node{string s;int num;}node[N];
vector<ANS> v;
vector<int> G[10];
map <string,int> mp;

signed main(){
//  freopen("D.in","r",stdin);
//  freopen("D.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin>>T;
  mp["inw"]=0;
  mp["iii"]=1;mp["iin"]=2;mp["inn"]=3;
  mp["iiw"]=4;mp["iww"]=5;mp["nnn"]=6;
  mp["nnw"]=7;mp["nww"]=8;mp["www"]=9;

  while(T--){
    cin>>m;
    
    v.clear();
    for(int i=0;i<10;++i) G[i].clear();
    
    for(int i=1;i<=m;++i){
      cin>>node[i].s; node[i].num=i;
      sort(All(node[i].s));
      G[mp[node[i].s]].push_back(node[i].num);
    }

    if(G[1].size()){//iii
      while(G[6].size()&&G[1].size()){
        //iii+nnn-->iin,inn
        v.push_back({node[G[1].back()].num,'i',node[G[6].back()].num,'n'});
        G[2].push_back(G[1].back()),G[1].pop_back();
        G[3].push_back(G[6].back()),G[6].pop_back();
      }
      while(G[9].size()&&G[1].size()){
        //iii+www-->iiw,iww
        v.push_back({node[G[1].back()].num,'i',node[G[9].back()].num,'w'});
        G[4].push_back(G[1].back()),G[1].pop_back();
        G[5].push_back(G[9].back()),G[9].pop_back();
      }
      
      while(G[8].size()&&G[1].size()){
        //iii+nww-->iiw,inw
        v.push_back({node[G[1].back()].num,'i',node[G[8].back()].num,'w'});
        G[4].push_back(G[1].back()),G[1].pop_back(),G[8].pop_back();
      }
      while(G[7].size()&&G[1].size()){
        //iii+nnw-->iin,inw
        v.push_back({node[G[1].back()].num,'i',node[G[7].back()].num,'n'});
        G[2].push_back(G[1].back()),G[1].pop_back(),G[7].pop_back();
      }
    }
    /*
      mp["iii"]=1;mp["iin"]=2;mp["inn"]=3;
      mp["iiw"]=4;mp["iww"]=5;mp["nnn"]=6;
      mp["nnw"]=7;mp["nww"]=8;mp["www"]=9;
    */
    if(G[6].size()){//nnn
      while(G[9].size()&&G[6].size()){
        //nnn+www-->nnw,nww
        v.push_back({node[G[6].back()].num,'n',node[G[9].back()].num,'w'});
        G[7].push_back(G[6].back()),G[6].pop_back();
        G[8].push_back(G[9].back()),G[9].pop_back();
      }

      while(G[6].size()&&G[5].size()){
        //nnn+iww-->nnw,inw
        v.push_back({node[G[5].back()].num,'w',node[G[6].back()].num,'n'});
        G[7].push_back(G[6].back()),G[6].pop_back(),G[5].pop_back();
      }
      while(G[6].size()&&G[4].size()){
        //nnn+iiw-->inn,inw
        v.push_back({node[G[4].back()].num,'i',node[G[6].back()].num,'n'});
        G[3].push_back(G[6].back()),G[6].pop_back(),G[4].pop_back();
      }
    }
    /*
      mp["iii"]=1;mp["iin"]=2;mp["inn"]=3;
      mp["iiw"]=4;mp["iww"]=5;mp["nnn"]=6;
      mp["nnw"]=7;mp["nww"]=8;mp["www"]=9;
    */
    if(G[9].size()){//www
      while(G[9].size()&&G[2].size()){
        //www+iin-->iww,inw
        v.push_back({node[G[2].back()].num,'i',node[G[9].back()].num,'w'});
        G[5].push_back(G[9].back()),G[9].pop_back(),G[2].pop_back();
      }
      while(G[9].size()&&G[3].size()){
        //www+inn-->nww,inw
        v.push_back({node[G[3].back()].num,'n',node[G[9].back()].num,'w'});
        G[8].push_back(G[9].back()),G[9].pop_back(),G[3].pop_back();
      }
    }

    //---
    /*
      mp["iii"]=1;mp["iin"]=2;mp["inn"]=3;
      mp["iiw"]=4;mp["iww"]=5;mp["nnn"]=6;
      mp["nnw"]=7;mp["nww"]=8;mp["www"]=9;
    */
    if(G[2].size()){
			//iin--nww
      while(G[2].size()&&G[8].size()){
        //iin+nww-->inw+inw
        v.push_back({node[G[2].back()].num,'i',node[G[8].back()].num,'w'});
        G[2].pop_back(),G[8].pop_back();
      }
      //iin--iww
      while(G[2].size()&&G[5].size()){
        //iin+iww-->iiw+inw
        v.push_back({node[G[2].back()].num,'i',node[G[5].back()].num,'w'});
        G[4].push_back(G[5].back()),G[2].pop_back(),G[5].pop_back();
      }
    }
    /*
      mp["iii"]=1;mp["iin"]=2;mp["inn"]=3;
      mp["iiw"]=4;mp["iww"]=5;mp["nnn"]=6;
      mp["nnw"]=7;mp["nww"]=8;mp["www"]=9;
    */
    if(G[3].size()){//inn--iww
      while(G[3].size()&&G[5].size()){
        //inn+iww-->inw+inw
        v.push_back({node[G[3].back()].num,'n',node[G[5].back()].num,'w'});
        G[3].pop_back(),G[5].pop_back();
      }
      //inn--nww
      while(G[3].size()&&G[8].size()){
        //inn+nww-->nnw+inw
        v.push_back({node[G[3].back()].num,'n',node[G[8].back()].num,'w'});
        G[7].push_back(G[8].back()),G[8].pop_back(),G[3].pop_back();
      }
    }

    if(G[4].size()){//iiw--nnw
      while(G[4].size()&&G[7].size()){
        //inn+iww-->inw+inw
        v.push_back({node[G[4].back()].num,'i',node[G[7].back()].num,'n'});
        G[4].pop_back(),G[7].pop_back();
      }
    }

    cout<<v.size()<<'\n';
    for(ANS x:v)
      cout<<x.a<<" "<<x.A<<' '<<x.b<<" "<<x.B<<'\n';
  }
  
  return 0;
}
/*//inw
1
3
www
iii
nnn

*/
