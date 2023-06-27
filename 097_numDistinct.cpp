class Solution {
public:
    //不同的子序列，给定一个字符串s和一个字符串t，计算s中有多少个不同的子序列和t相同
    //思路：动态规划，dp[i][j]表示s[0...i]中有多少个子序列和t[0...j]相同
    int numDistinct(string s, string t) {
        int m=s.size(),n=t.size();
        vector<vector<long>> dp(m+1,vector<long>(n+1,0));
        //初始化
        for(int i=0;i<=m;i++){
            dp[i][0] = 1;
        }
        //状态转移方程
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = dp[i-1][j];
                if(s[i-1] == t[j-1]){
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};