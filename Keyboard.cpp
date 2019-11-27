#include <iostream>
#include <cmath>
#include <vector>
#include <set>
 
using namespace std;
 
using ll = long long;
 
vector<pair<int, int>> centers[256];
 
int distance_squared(int x1, int y1, int x2, int y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<string> a(n);
  vector<bool> there(256);
  vector<pair<int, int>> S;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < m; j++) {
      there[a[i][j]] = true;
      if (a[i][j] == 'S') {
        S.emplace_back(i, j);
        continue;
      }
      centers[a[i][j]].push_back({i, j});
    }
  }
  int dis[256]{};
  for (char i = 'a'; i <= 'z'; i++) {
    int mn = (int) 1e9;
    for (auto x : centers[i]) {
      for (auto y : S) {
        mn = min(mn, distance_squared(x.first, x.second, y.first, y.second));
      }
    }
    dis[i] = mn;
  }
  int t;
  cin >> t;
  string text;
  cin >> text;
  int ans = 0;
  for (int i = 0; i < t; i++) {
    if (isupper(text[i]) && S.empty()) {
      puts("-1");
      return 0;
    }
    if (!there[tolower(text[i])]) {
      puts("-1");
      return 0;
    }
    if (isupper(text[i])) {
      if (dis[tolower(text[i])] > x * x) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
