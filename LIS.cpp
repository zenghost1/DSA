#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int lis(vector<int>& a){
        sort(a.begin(),a.end());
        int n = a.size();
        vector<int> dp(n,1);
        vector<int> previdx(n,-1);

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(a[i] > a[j] && dp[i] > dp[j]+1){
                    dp[i] = dp[j] +1;
                    previdx[i] = j;
                }
            }
            if(dp[i] > dp[maxi]) maxi = i; 
        }

        int t = previdx[maxi];
        vector<int> ans;

        while(t>=0){
            ans.push_back(a[t]);
            t = previdx[t];
        }

        return ans;

    }
}