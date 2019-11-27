#include <iostream>

using namespace std;

using ll = long long;

void no() {
  puts("-1");
  exit(0);
}
int main() {
  ll k;
  cin >> k;
  if (k > 36) {
    no();
  }
  while (k > 0) {
    if (k >= 2) {
      cout << 8;
      k -= 2;
    } else {
      cout << 6;
      k--;
    }
  }
  return 0;
}
