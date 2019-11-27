#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
 
 
using ll = long long;
 
using namespace std;
 
int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end(), [&](pair<int, int> p1, pair<int, int> p2) {
       if (p1.second != p2.second)
          return p1.second > p2.second;
       return p1.first > p2.first;
  });
  ll ans = 0;
  for (int i = 0; i < m; i++) {
    ans += a[i].first * a[i].second;
    n -= a[i].first;
    if (n < 0) {
      ans -= a[i].first * a[i].second;
      n += a[i].first;
      ans += n * a[i].second;
      break;
    }
  }
  cout << ans << '\n';
  return 0;
}
