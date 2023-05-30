//
// Created by 23116 on 2023/5/2.
//
class Solution {
public:
    //思路：将0变为-1，然后求和为0的最长子数组的长度
    int findMaxLength(vector<int>& nums) {
        int sum=0;
        int res=0;
        unordered_map<int,int> m;
        m[0]=-1;
        for(int i=0;i<nums.size();++i){
            sum+=nums[i]==0?-1:1;
            if(m.find(sum)!=m.end()){
                res = max(res,i-m[sum]);
            }
            else{
                m[sum] = i;
            }
        }
        return res;
    }
};