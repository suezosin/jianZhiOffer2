//
// Created by 23116 on 2023/5/2.
//
class Solution {
public:
    //左右两边的和相等，即左边的和等于总和减去左边的和减去当前值
    //思路：先求出总和，然后从左到右遍历，每次减去当前值，如果左边的和等于总和减去左边的和减去当前值，那么就返回当前索引
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for(int i=0;i<nums.size();++i){
            total+=nums[i];
        }
        int sum=0;
        for(int j=0;j<nums.size();++j){
            sum+=nums[j];
            if(sum-nums[j]==total-sum)
                return j;
        }
        return -1;
    }
};