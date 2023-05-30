//
// Created by 23116 on 2023/4/27.
//
class Solution {
public:
    int rob(vector<int>& nums) {
        //nums的长度用nums.size()表示
        if(nums.size()==0)
            return 0;
        //新建一个数组，用来存储到第i个房子时，能偷到的最大金额
        vector<int> dp(nums.siz9e()+1,0); //初始化为0,长度为nums.size()+1
        dp[1]=nums[0]; //第一个房子只有一个，所以只能偷第一个房子
        for(int i=2;i<=nums.size();i++){
            //第i个房子的最大金额为：偷第i个房子的金额+到第i-2个房子时的最大金额 与 不偷第i个房子的金额+到第i-1个房子时的最大金额 之间的最大值
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[nums.size()];
    }
};
