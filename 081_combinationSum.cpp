class Solution {
public:
    //思路：回溯法，每次递归都有两种选择，选或者不选,数组中的元素互不相同
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(res,temp,candidates,target,0);
        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& temp, vector<int>& candidates, int target, int start){
        if(target<0) return;
        if(target==0){
            res.push_back(temp);
            return;
        }
        for(int i=start; i<candidates.size();i++){
            temp.push_back(i);
            backtrack(res,temp,n,k,i+1);
            temp.pop_back();
        }
    }
};