#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

  int cnt =0;
  int n, m;
  int a[1002][1002];
  int dx[4]={-1, 0, 1, 0};
  int dy[4]={0, -1, 0, 1};
  void dfs(int x, int y){
     a[x][y]=0;
     for (int i=0; i<4; i++){
        int x1=x+dx[i];
        int y1=y+dy[i];
        if (x1>=0 && x1<n && y1>=0 && y1<m && a[x1][y1]){
          dfs(x1, y1);
        }
     }
  }
int main() {
   cin >> n >>m;
   for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
         char x; cin >> x;
         if (x=='.') a[i][j]=1;
         else a[i][j]=0;
      }
   }
   for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
         if (a[i][j]){
            cnt++;
            dfs(i, j);
         }
      }
   }
   cout << cnt;
}
