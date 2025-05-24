#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

  int n, m;
  vector<int> ke[1002];
    int used[1002];
    int parent[1002];
    int sz[1002];
  void init(){
     for (int i=1; i<=n; i++){
       parent[i]=i;
       sz[i]=1;
     }
  }
  int find(int u){
    if(u == parent[u]){
      return u;
    }
   else return parent[u]=find(parent[u]);
  }
  bool Union(int u, int v){
      u=find(u);
      v=find(v);
     if (u==v) return false;
     if (sz[u] < sz[v]){
        parent[u]=v;
        sz[v]+=sz[u];
     }
     else {
      parent[v]=u;
      sz[u]+=sz[v];
     }
     return true;
  }

int main() {
     cin >> n >> m;
     init();
     int cnt=n;
     while (m--){
      int x, y; cin >> x >> y;
      if (Union(x,y)) cnt--;
     }
     cout << cnt;
}
