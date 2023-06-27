class Solution {
public:
    //三角形最小路径和，给定一个三角形，找到从上到下的最小路径和，每一步只能移动到下一行中相邻的结点上
    //思路：动态规划，dp[i][j]表示从(0,0)到(i,j)的最小路径和
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        //初始化
        dp[0][0] = triangle[0][0];
        //状态转移方程为：dp[i][j] = min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j]
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                if(j==0){
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }
                else if(j==i){
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }
                else{
                    dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]) + triangle[i][j];
                }
            }
        }
        //返回结果
        int res = dp[n-1][0];
        for(int i=1;i<n;i++){
            res = min(res,dp[n-1][i]);
        }
        return res;
    }
};