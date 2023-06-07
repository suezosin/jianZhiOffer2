class Solution {
public:
    //思路：回溯法，每次递归都有两种选择，选或者不选,数组中的元素互不相同
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());//排序,用于判断重复元素
        backtrack(res,temp,candidates,target,0);
        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& temp, vector<int>& candidates, int target, int start){
        if(target<0) return;
        if(target==0){
            res.push_back(temp);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(i>start && candidates[i]==candidates[i-1]) continue;//判断重复元素
            temp.push_back(candidates[i]);
            backtrack(res,temp,candidates,target-candidates[i],i+1);//限制重复选取，故i加1
            temp.pop_back();
        }
    }
};