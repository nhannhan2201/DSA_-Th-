#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

  int n, m;
  int sz[200006];
  int parent[200006];
  vector<pair<pair<int, int>, int>> v;
  bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
   return a.second < b.second;
  }
  int find(int u){
   if (u==parent[u]){
      return u;
   }
   else return parent[u]=find(parent[u]);
  }
  bool Union(int u, int v){
       u=find(u);
       v=find(v);
      if (u==v) return false;
      else {
         if(sz[v]<sz[u]);
            swap(u, v);
            sz[v]+=sz[u];
            parent[u]=v;
            return true;
      }
  }
  void init(){
   for (int i=1; i<=n; i++){
      sz[i]=1;
      parent[i]=i;
   }
  }
int main() {
   cin >> n >>m;
     init();
     while (m--){
      int x, y, z;
      cin >> x >> y >> z;
      v.push_back({{x,y},z});
     }
     sort(v.begin(), v.end(), cmp);
     int cnt=0;
     ll res=0;
   for (auto x : v){
      if (Union(x.first.first, x.first.second)){
           cnt++;
           res+=x.second;
      }
   }
   if (cnt <n-1) cout << "IMPOSSIBLE";
   else cout << res;
}
