#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

 
int main() {
   int n; cin >> n;
   vector <pair<int, int>> v;
   cin.ignore();
   for (int i=1; i<=n; i++){
     string s; 
     getline(cin, s);
     stringstream ss(s);
     string x;
     while (ss >> x){
        int j=stoi(x);
        v.push_back({i, j});
     }
   }
   sort(v.begin(), v.end());
   for (auto x : v){
    cout << x.first << " " << x.second << endl;
   }
   return 0;
}

