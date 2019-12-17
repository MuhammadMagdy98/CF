#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <iomanip>

using namespace std;

using ll = long long;

const int N = 2e6;
string arr[N];

bool custom_compare(string a, string b) {
    if (a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cnt = 1;
    for (char i = 'A'; i <= 'Z'; i++) {
        string s;
        s += i;
        arr[cnt] = s;
        cnt++;
    }
    for (char i = 'A'; i <= 'Z'; i++) {
        for (char j = 'A'; j <= 'Z'; j++) {
            string s;
            s += i;
            s += j;
            arr[cnt] = s;
            cnt++;
        }
    }
    for (int i = 'A'; i <= 'Z'; i++) {
        for (char j = 'A'; j <= 'Z'; j++) {
            for (char k = 'A'; k <= 'Z'; k++) {
                string s;
                s += i;
                s += j;
                s += k;
                arr[cnt] = s;
                cnt++;
            }
        }
    }
    for (char i = 'A'; i <= 'Z'; i++) {
        for (char j = 'A'; j <= 'Z'; j++) {
            for (char k = 'A'; k <= 'Z'; k++) {
                for (char l = 'A'; l <= 'Z'; l++) {
                    string s;
                    s += i;
                    s += j;
                    s += k;
                    s += l;
                    arr[cnt] = s;
                    cnt++;
                }
            }
        }
    }
    for (char i = 'A'; i <= 'C'; i++) {
        for (char j = 'A'; j <= 'Z'; j++) {
            for (char k = 'A'; k <= 'Z'; k++) {
                for (char l = 'A'; l <= 'Z'; l++) {
                    for (char m = 'A'; m <= 'Z'; m++) {
                        string s;
                        s += i;
                        s += j;
                        s += k;
                        s += l;
                        s += m;
                        arr[cnt] = s;
                        cnt++;
                    }
                }
            }
        }
    }
    int n;
    cin >> n;
    sort(arr + 1, arr + cnt, [](string a, string b) {
        if (a.length() == b.length()) return a < b;
        return a.length() < b.length();
    });
    while (n--) {
        string s;
        cin >> s;
        bool first = false;
        if (s[0] == 'R') {
            int x = s.find('C');
            if (x >= 1 && isdigit(s[x - 1]) && isdigit(s[x + 1])) {
                first = true;
            }
        }
        if (first) {
            s.find('C');
            int x = stoi(s.substr(s.find('C') + 1));
            string tmp;
            for (int i = 1; i < s.length() && s[i] != 'C'; i++) {
                tmp += s[i];
            }
            cout << arr[x] << tmp << '\n';
        } else {
            int i = 0;
            string tmp;
            while (i < s.length() && isalpha(s[i])) {
                tmp += s[i];
                i++;
            }
            int low = 1, high = cnt - 1;
            int idx = 0;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (arr[mid] == tmp) {
                    idx = mid;
                    break;
                }
                if (custom_compare(arr[mid], tmp)) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            cout << 'R' << s.substr(i) << 'C' << idx << '\n';
        }
    }
    return 0;
}
