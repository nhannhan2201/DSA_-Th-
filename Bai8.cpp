#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(NULL);
  int n; cin >> n;
  vector <pair<pair<int, int>, int>> v;
   for (int i=1; i<=n; i++){
    for (int j=1; j<=n; j++){
       int x; cin >> x;
       if (x && i<j){
        v.push_back({{i, j}, x});
       }
    }
   }
   sort(v.begin(), v.end());
   for (auto x : v){
    cout << x.first.first << " " << x.first.second << " " << x.second << endl;
   }
}

