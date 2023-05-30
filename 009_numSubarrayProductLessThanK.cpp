//
// Created by 23116 on 2023/5/2.
//
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //思路：滑动窗口, 小于目标值时，右边界右移，大于目标值时，左边界右移，直到小于目标值，然后右边界右移，以此类推，直到右边界到达数组末尾，结束，
        // 这是因为如果一个子数组的乘积小于k，那么这个子数组的所有子数组的乘积也都小于k，如果大于k,包含这个子数组的子数组的乘积也都大于k
        int left,right=0;
        int count=0;
        int product=1;
        if (k<=1) return 0;
        for(left=0;left<nums.size();left++){
            while(right<nums.size()&&product*nums[right]<k){//这里的product*nums[right]<k是因为如果product*nums[right]==k,那么这个子数组的乘积就等于k了，所以要小于k
                product*=nums[right];
                right++;
            }//这里的right-left是因为right和left都是索引，所以要加1
            count+=right-left;
            if(left==right)//这里的left==right是因为如果left==right,那么product=1，所以要让right++，否则会死循环
                right++;
            else //这里的product/=nums[left]是因为如果product/=nums[left],那么这个子数组的乘积就等于k了，所以要大于k
                product/=nums[left];
        }
        return count;
    }
};
