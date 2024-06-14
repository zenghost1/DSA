

vector<vector<int>> dp(n+1, vector<int>dp(m+1));

for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
        int eq = (s[i-1] == r[j-1]) ? 1 + dp[i-1][j-1] : 0;
        int noteq = max(dp[i-1][j], dp[i][j-1]);
        dp[i][j] = max(eq, noteq);
    }
}

int same = dp[n][m];

// to print LCS

int n = s.size(); int m = r.size();
vector<vector<string>> dp(n+1, vector<string>(m+1,""));

for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
        string eq = (s[i-1] == r[j-1]) ? dp[i-1][j-1] + s[i-1] : "";
        string noteq = dp[i-1][j].size() > dp[i][j-1].size() ? dp[i-1][j] : dp[i][j-1];
        dp[i][j] = eq.size() > noteq.size() ? eq : noteq;
    }
}

// OR space optimised way is to :-

//print lcs
int i=n,j=m;
while(i>0 && j>0)
{
    if(s1[i-1]==s2[j-1])
    {
        res.push_back(s1[i-1]);
        i--;
        j--;
    }
    else
    {
        if(t[i-1][j]>t[i][j-1])
        {
            res.push_back(s1[i-1]);
            i--;
        } else{
            res.push_back(s2[j-1]);
            j--;
        }
    }
}