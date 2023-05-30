//
// Created by 23116 on 2023/5/2.
//
//思路：先排序，然后定义左指针和右指针，左指针从i+1开始，右指针从数组末尾开始，当左指针小于右指针时，循环
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //答案中不能有重复的三元组，所以先排序
        sort(nums.begin(),nums.end()); //python中的sort()函数是原地排序，不会返回新的列表,而C++中的sort()函数是返回新的列表
        vector<vector<int>> res;
        for(int i=0;i<nums.size();i++){
            //如果nums[i]>0,那么三数之和一定大于0，所以直接返回res
            if(nums[i]>0)
                return res;
            //如果nums[i]==nums[i-1],那么说明这个数已经被考虑过了，所以跳过,这里的i>0是为了防止数组越界
            if(i>0 && nums[i]==nums[i-1]) //&&是逻辑与，||是逻辑或
                continue;
            //定义左指针和右指针，左指针从i+1开始，右指针从数组末尾开始，当左指针小于右指针时，循环
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                //如果nums[i]+nums[left]+nums[right]==0,那么就将这三个数加入res中
                if(nums[i]+nums[left]+nums[right]==0){
                    res.push_back({nums[i],nums[left],nums[right]});
                    //如果nums[left]==nums[left+1],那么说明这个数已经被考虑过了，所以跳过
                    while(left<right && nums[left]==nums[left+1])
                        left++;
                    //如果nums[right]==nums[right-1],那么说明这个数已经被考虑过了，所以跳过
                    while(left<right && nums[right]==nums[right-1])
                        right--;
                    //如果nums[left]!=nums[left+1]或者nums[right]!=nums[right-1],那么说明这个数没有被考虑过，所以left++，right--
                    left++;
                    right--;
                }
                //如果nums[i]+nums[left]+nums[right]<0,那么说明三数之和小于0，所以left++
                else if(nums[i]+nums[left]+nums[right]<0)
                    left++;
                //如果nums[i]+nums[left]+nums[right]>0,那么说明三数之和大于0，所以right--
                else
                    right--;
            }
        }
        return res;
    }
};
