#include <bits/stdc++.h>

using namespace std;
bool perfect(int n) {
int y = sqrt(n);
if (y * y == n)
  return true;
return false;

}
int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (!perfect(v[i]))
        ans.push_back(v[i]);
  }
  cout << *max_element(ans.begin(), ans.end());

  return 0;
}
