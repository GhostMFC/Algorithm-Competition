#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  while(1){
    system("gen.exe");
    system("a.exe");
    system("b.exe");
    if(system("fc a.txt b.txt"))
      break;
  }
  
  return 0;
}