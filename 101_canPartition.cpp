class Solution {
public:
    //分割等和子集，给定一个只包含正整数的非空数组，是否可以将这个数组分割成两个子集，使得两个子集的元素和相等
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return false;
        int sum=0,maxNum=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            maxNum = max(maxNum,nums[i]);
        }
        if(sum%2!=0) return false;
        int target = sum/2;
        if(maxNum>target) return false;
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        //初始化
        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }
        dp[0][nums[0]] = 1;//这里要注意，如果nums[0]==0，那么dp[0][0]就会被初始化为1，这样就会出错，所以要单独处理
        //状态转移方程
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                if(j>=nums[i]){
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i]];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n-1][target]==1;
    }
};