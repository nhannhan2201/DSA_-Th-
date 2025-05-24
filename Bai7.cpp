#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

  int a[1005][1005];
int main(){
    int n, m;
    cin >> n >> m;
    while (m--){
       int x, y; cin >> x >> y;
       a[x][y]=1;
       a[y][x]=1;
    } 
    for (int i=1; i<=n; i++){
      for (int j=1; j<=n; j++){
        cout << a[i][j] << " ";
      }
      cout << endl;
    }
 }

