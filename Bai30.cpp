#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

  int n;
  int s,t,u,v;
  vector<int> ke[1002];
  int a[1002][1002];
  int d[1002][1002];
  int dx[8]={-2, -2, -1, -1, 1, 1, 2, 2};
  int dy[8]={-1, 1, -2, 2, -2, 2, -1, 1};
  int bfs(int s, int t){
     queue <pair<int, int>> q;
     q.push({s,t});
     while(!q.empty()){
      pair<int, int> p=q.front();
      q.pop();
      int i=p.first, j=p.second;
      if (i==u && j==v) return d[i][j];
      for (int k=0; k<8; k++){
        int i1=i+dx[k], j1=j+dy[k];
        if (i1 >=1 && i1<=n && j1>=1 && j1<=n && a[i1][j1]==1){
          a[i1][j1]=0;
          q.push({i1, j1});
          d[i1][j1]=d[i][j]+1;
        }
      }
     }
     return -1;
  }
int main() {
   cin >> n ;
   cin >> s >> t >> u >> v;
   for (int i=1; i<=n; i++){
    for (int j=1; j<=n; j++){
      cin >> a[i][j];
    }
   }
   cout << bfs(s, t);
}
