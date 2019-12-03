#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    int y = b - a;
    int x = (y / 5) + (y % 5 / 2) + (y % 5 % 2);
    int five = y / 5;
    int two =  y % 5 / 2;
    int one = y % 5 % 2;
    if (a + five * 5 + two * 2 + one > b) x--;
    if (a + five * 5 + two * 2 + one < b) x++;
    cout << x << '\n';
  }
  return 0;
}

 
