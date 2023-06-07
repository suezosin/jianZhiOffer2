class Solution {
public:
    //思路，利用快速排序的思想，每次选取一个pivot，将数组分为两部分，左边的比pivot大，右边的比pivot小，然后判断pivot的位置是否为k-1，如果是，则返回pivot，如果不是，则继续在左边或者右边寻找
    int findKthLargest(vector<int>& nums, int k) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int pivot = partition(nums,left,right);
            if(pivot==k-1) return nums[pivot];
            else if(pivot>k-1) right = pivot-1;
            else left = pivot+1;
        }
        return -1;
    }

    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[left];
        while(left<right){
            while(left<right&&nums[right]<=pivot) right--;
            nums[left] = nums[right];
            while(left<right&&nums[left]>=pivot) left++;
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }
};