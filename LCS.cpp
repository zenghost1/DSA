

vector<vector<int>> dp(n+1, vector<int>dp(m+1));

for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
        int eq = (s[i-1] == r[j-1]) ? 1 + dp[i-1][j-1] : 0;
        int noteq = max(dp[i-1][j], dp[i][j-1]);
        dp[i][j] = max(eq, noteq);
    }
}

int same = dp[n][m];