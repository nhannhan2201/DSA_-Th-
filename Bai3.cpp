#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

 vector <int> ke[1002];
int main() {
   int n, m;
   cin >> n >> m;
   while (m--){
    int u,v;
    cin >> u >> v;
    ke[u].push_back(v);
   }
   for (int i=1; i<=n; i++){
    sort (ke[i].begin(), ke[i].end());
    cout << i << " : ";
    for (int x : ke[i]){
        cout << x << " ";
    }
    cout << endl;
   }
   return 0;
}
