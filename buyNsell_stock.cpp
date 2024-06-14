// FOR 2 Transactions
int maxProfit(vector<int>& prices) {
    n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(5, 0));
    
    for(int i=n-1; i>=0; i--){
        for(int j=3; j>=0; j--){
            int profit = dp[i+1][j+1] + ((j%2 == 1) ? prices[i] : -prices[i]);
            int skip = dp[i+1][j];
            dp[i][j] = max(profit, skip);
        }
    }

    // ans to possible buy and sell stocks with buy1 choice on day 0
    return dp[0][0];
}

// to generalize for k transactions
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    vector<vector<int>> dp(n + 1, vector<int>(2*k+1, 0));        

    for(int i=n-1; i>=0; i--){
        for(int j=2*k-1; j>=0; j--){
            int profit = dp[i+1][j+1] + ((j%2 == 1) ? prices[i] : -prices[i]);
            int skip = dp[i+1][j];
            dp[i][j] = max(profit, skip);
        }
    }

    cout<< "b1 s1 b2 s2 ..... d" << endl;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=4; j++){
            cout<< dp[i][j] << "  ";
        }
        cout<< endl;
    }

    return dp[0][0];
}