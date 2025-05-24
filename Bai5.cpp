#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

  int a[1002][1002];
int main() {
   int n; cin >> n;
   vector <int> ke[1002];
   vector <pair<int,int>> v;
   for (int i=1; i<=n; i++){
    for (int j=1; j<=n; j++){
        cin >> a[i][j];
        if (a[i][j]){
           ke[i].push_back(j); 
           if (i>j){
             v.push_back({i, j});
           }
        }
   }
}
  sort(v.begin(), v.end());
  for (auto x : v){
    cout << x.first << " " << x.second << endl;
  }
  cout << endl;
  for (int i=1; i<=n; i++){
    sort (ke[i].begin(), ke[i].end());
    cout << i << " : ";
    for (auto x : ke[i]){
        cout << x << " ";
    }
    cout << endl;
  }
}
