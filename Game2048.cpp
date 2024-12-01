#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        long long ans = 1;
        bool check = true;

        int b = 0;
        while (n > 0) {
            if (b == 0 && (n & 1)) {
                check = false;
                break;
            }
            if (b == 1 && (n & 1)) {
                check = false;
                break;
            }
            if (b >= 2 && (n & 1)) {
                if (b == 2) {

                } else {
                    ans = (ans * (b - 2)) % MOD;
                }
            }
            n >>= 1;
            b++;
        }

        if (!check) {
            cout << 0 << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
