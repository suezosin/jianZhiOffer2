class Solution {
public:
    //思路：回溯法，每次递归都有两种选择，选或者不选,数组中的元素互不相同
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(res,temp,nums);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums){
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(find(temp.begin(),temp.end(),nums[i])!=temp.end()) continue; //说明nums[i]已在temp中，故继续
            temp.push_back(nums[i]);
            backtrack(res,temp,nums);
            temp.pop_back();
        }
    }
};