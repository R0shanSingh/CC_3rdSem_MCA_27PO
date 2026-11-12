// https://leetcode.com/problems/number-of-ways-to-earn-points/submissions/2194354421/

class Solution {
public:
    int waysToReachTarget(int target, std::vector<std::vector<int>>& types) {
        const int MOD = 1e9 + 7;
        std::vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (const auto& type : types) {
            int count = type[0];
            int marks = type[1];

            for (int j = target; j >= 0; --j) {
                for (int k = 1; k <= count; ++k) {
                    if (j - k * marks >= 0) {
                        dp[j] = (dp[j] + dp[j - k * marks]) % MOD;
                    } 
                    else{
                        break;
                    }
                }
            }
        }
        return dp[target];
    }
};
