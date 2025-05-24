#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

  int n, m, a[505][505], c[505][505];
  int dx[4]={0, 0, 1, -1};
  int dy[4]={1, -1, 0, 0};
   void bfs(){
      queue<pair <int, int>> q;
      q.push({0,0});
      c[0][0]=a[0][0];
      while (q.size()){
         auto x=q.front();
         q.pop();
         for (int k=0; k<4; k++){
            int i=x.first + dx[k], j=x.second + dy[k];
            if (i >=0 && i<n && j >=0 && j<m && c[i][j] > c[x.first][x.second]+a[i][j]){
               c[i][j]=c[x.first][x.second]+a[i][j];
               q.push({i, j});
            }
         }
      }
   }
int main() {
   cin >> n >> m;
   for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
         cin >> a[i][j];
         c[i][j]=MOD;
      }
   }
   bfs();
   cout << c[n-1][m-1];
}
