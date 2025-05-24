#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

  int cnt =0;
  int n, m;
  vector<int> ke[1002];
  int used[1002];
  int bac[1002];
  vector<int> v;
  int lead;
  void nhap(){
    cin >> n >> m;
    for (int i=0; i<m; i++){
      int x, y; cin >> x >> y;
      bac[x]++; bac[y]++;
      ke[x].push_back(y);
      ke[y].push_back(x);
    }
  }
  void dfs(int u){
    if (bac[u]>bac[lead] || bac[u]==bac[lead] && u < lead){
       lead=u;
    }
    used[u]=1;
    for (int x : ke[u]){
      if (!used[x]){
         dfs(x);
      }
    }
  }
int main() {
   nhap();
   for (int i=1; i<=n; i++){
      if (!used[i]){
         lead=i;
         dfs(i);
         v.push_back(lead);
      }
   }
   sort(v.begin(), v.end());
   for (int x : v) cout << x << " ";
}
