#include <bits/stdc++.h>
using namespace std;

int findTargetSumWays(vector<int> &nums, int target) {
    int sum = 0;
    for(int num : nums) sum += num;

    int s = (sum + target) / 2;
    vector<int> dp(s + 1, 0);
    dp[0] = 1;

    for(int num : nums) {
        for(int j = s; j >= num; j--) {
            dp[j] += dp[j - num];
        }
    }

    return dp[s];
}

void solve() {
    vector<int> arr = {1, 1, 1, 1};
    int target = 4;

    int ans = findTargetSumWays(arr, target);
    cout << ans << "\n";

}