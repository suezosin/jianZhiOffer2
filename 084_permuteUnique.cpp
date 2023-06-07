class Solution {
public:
    //思路：回溯法，每次递归都有两种选择，选或者不选,数组中的元素可能相同
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> used(nums.size(),false);
        sort(nums.begin(),nums.end());//排序,用于判断重复元素
        backtrack(res,temp,nums,used);
        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, vector<bool>& used){
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;//判断重复元素
            if(i>0 && nums[i]==nums[i-1] && !used[i-1]) continue;//判断重复元素
            temp.push_back(nums[i]);
            used[i]=true;
            backtrack(res,temp,nums,used); //要记录的是used，而不是i，改变的是temp，而不是nums
            used[i]=false;
            temp.pop_back();
        }
    }
};