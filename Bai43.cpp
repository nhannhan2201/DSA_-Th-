#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

  int n, m, s, t, u, v;
  int a[505][505];
  int dx[4]={-1, 0, 1, 0};
  int dy[4]={0, -1, 0, 1};
  void nhap(){
   cin >> n >> m;
   for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
         char c; cin >> c;
         if (c=='S'){
            s=i; t=j;
         }
         if (c=='T'){
            u=i; v=j;
         }
         if(c!='*') a[i][j]=1;
         else a[i][j]=0;
      }
   }
  } 
  bool ok=false;
  void dfs(int i, int j, int d, int cnt){
     if (cnt>2 || ok) return ;
     a[i][j]=0;
     if(i==u && j==v) ok=1;
     for (int k=0; k<4; k++){
          int i1= i+dx[k], j1=j+dy[k];
          if (i1>=0 && i1<n && j1>=0 && j1<m && a[i1][j1]){
            if (k==d){
               dfs(i1, j1, k, cnt);
            }
            else dfs(i1, j1, k, cnt+1);
          }
     }
     a[i][j]=1;
  }
int main() {
    nhap();
    dfs(s, t, -1, -1);
    if (ok) cout << "YES";
    else cout << "NO";
}
