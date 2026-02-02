#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int solver() {
    int n, a, b; cin >> n >> a >> b;
    long long l = min(a, b);
    long long r = (long long)n * min(a, b);

    long long lcm = (long long)a * b / gcd(a, b);

    while (l < r) {
        long long mid = l + (r - l) / 2;

        long long count =
            mid / a +
            mid / b -
            mid / lcm;

        if (count >= n)
            r = mid;
        else
            l = mid + 1;
    }

    return l % MOD;
}


int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int input = 1;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> input;
    while(input--) solver();

}