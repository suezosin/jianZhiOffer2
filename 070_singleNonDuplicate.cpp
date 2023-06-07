class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()<=1) return nums[0];
        int left=0,right=nums.size()/2;
        while(left<=right){
           int mid=left+(right-left)/2;
           if(nums[mid*2]!=nums[mid*2+1]){
               if(mid==0||nums[(mid-1)*2]==nums[mid*2-1]) return nums[mid*2];
               right = mid-1;
           }
           else{
               left = mid+1;
           }

        }
        return nums[nums.size()-1];
    }


};