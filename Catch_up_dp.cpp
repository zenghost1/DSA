/* An absolutely beautiful use of catch_up dp
Question is to tell the maximum damage a magician can do.
Ex. [1,1,3,4] -> 6
*/

// little different for i+1 thing I would have probably gone for checking the i-1 with index as i=1.

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        vector<long long> dp(100001, 0); long long max_dp = 0;
        sort(power.begin(), power.end());
        for(int i=0, j=0; i<power.size(); ++i){
            if(power[i] == power[max(0,i-1)])
                dp[i+1] = power[i] + dp[i];
            else{
                while(power[j] + 2 < power[i]){
                    max_dp = max(max_dp, dp[j+1]); 
                    j++;
                } 
                dp[i+1] = power[i] + max_dp;
            }
        }

        return *max_element(dp.begin(), dp.begin() + power.size() + 1);
    }
};

/* 
dp[i+1] represents the best result for ith spell. 
Apart from the special case where power[i] == power[i-1].
We take a max_dp runner which keeps track of max of dp till power[j] + 2 < power[i].
Once we know what is the max_dp till 2 less of our current power. We add it to the dp[i+1] for ith spell.
*/
j i
[0,1,2,3,6]
[1,1,3,4]