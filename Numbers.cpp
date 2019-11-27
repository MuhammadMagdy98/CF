#include <iostream>
#include <cmath>

using namespace std;

using ll = long long;

int get(int x, int base) {
  int ret = 0;
  while (x > 0) {
    ret += x % base;
    x /= base;
  }
  return ret;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 2; i < n; i++) {
    sum += get(n, i);
  }
  int a = sum;
  a /= gcd(sum, n - 2);
  int b = n - 2;
  b /= gcd(sum, n - 2);
  cout << a << '/' << b << '\n';
  return 0;
}
