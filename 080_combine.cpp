class Solution {
public:
    //思路：回溯法，每次递归都有两种选择，选或者不选,数组中的元素互不相同
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(res,temp,n,k,1);
        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& temp, int n, int k, int start){
        if(temp.size()==k){
            res.push_back(temp);
            return;
        }
        for(int i=start;i<=n;i++){
            temp.push_back(i);
            backtrack(res,temp,n,k,i+1);
            temp.pop_back();
        }
    }
};