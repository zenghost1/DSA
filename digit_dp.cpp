#include <bits/stdc++.h>
using namespace std;

int dp[100][2][100];

void reset(){
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
                dp[i][0][j] = -1;
                dp[i][1][j] = -1;
        }
    }
}

int dfs(string c, int pos, bool limit, int cnt, int k, int n, int d){
    if(pos == n){
        if(cnt == k) return 1;
        else return 0;
    }

    if(dp[pos][limit][cnt] != -1) return dp[pos][limit][cnt];

    int ans = 0;
    int maxnum = limit ? 9 : c[pos] - '0';

    for(int i=0; i<maxnum; i++){
        ans += dfs(c, pos+1, true, (i==d) ? cnt+1 : cnt, k, n, d);
    }

    ans += dfs(c, pos+1, limit, (maxnum==d) ? cnt+1 : cnt, k, n, d);

    return dp[pos][limit][cnt] = ans;
}

void solve()
{
    string a, b; cin>>a>>b;
    reset();
    int upper = dfs(b,0,false,0,2,b.size(),1);
    reset();
    int lower = dfs(a,0,false,0,3,a.size(),1);
    cout<< upper - lower << endl;
}


int main()
{
    int t=1;
    while(t--){
        solve();
    }

    return 0;
}