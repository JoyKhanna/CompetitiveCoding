class Solution {
public:

    int rec(int n, int m, vector<vector<int>> &obs, vector<vector<int>> &dp) {
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;
        if(obs[n][m] == 1) return 0;

        if(dp[n][m] != -1) return dp[n][m];
        return dp[n][m] = rec(n - 1, m, obs, dp) + rec(n, m - 1, obs, dp);
    }


    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1) return 0;

        vector<vector<int>> dp(n, vector<int> (m , - 1));
        return rec(n - 1, m - 1, obstacleGrid, dp);
    }
};