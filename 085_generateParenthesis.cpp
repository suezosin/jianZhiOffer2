class Solution {
public:
    //生成括号，n对括号，生成所有可能的括号组合
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res,"",0,0,n);
        return res;
    }
    void backtrack(vector<string>& res, string temp, int left, int right, int n){
        if(temp.size()==2*n){
            res.push_back(temp);
            return;
        }
        if(left<n) backtrack(res,temp+"(",left+1,right,n);
        if(right<left) backtrack(res,temp+")",left,right+1,n); //right<left，说明右括号的数量小于左括号的数量，故可以加右括号
    }
};