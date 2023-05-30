//
// Created by 23116 on 2023/5/2.
//
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //思路：滑动窗口, 小于目标值时，右边界右移，大于目标值时，左边界右移，直到小于目标值，然后右边界右移，以此类推，直到右边界到达数组末尾，结束
        int left=0,right=0;
        int sum=0;
        int res = INT_MAX; //INT_MAX是C++中int类型的最大值
        while(right<nums.size()){
            sum+=nums[right];
            while(sum>=target&&left<=right){
                res=min(res,right-left+1);//min()函数返回两个数中的最小值,这里的right-left+1是因为right和left都是索引，所以要加1,子数组长度为right-left+1
                sum-=nums[left];
                left++;
            }
            right++;
        }
        return res==INT_MAX?0:res;
    }
};