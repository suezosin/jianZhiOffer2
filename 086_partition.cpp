class Solution {
public:
    //回文串分割，给定一个字符串s，将s分割成一些子串，使每个子串都是回文串，返回s所有可能的分割方案，回溯法，每次递归都有两种选择，选或者不选，选的话，判断是否是回文串，不是的话，不选，直接跳过
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        backtrack(res,temp,s,0);
        return res;
    }
    void backtrack(vector<vector<string>>& res, vector<string>& temp, string s, int start){
        if(start==s.size()){
            res.push_back(temp);
            return;
        }
        for(int i=start;i<s.size();i++){
            if(isPalindrome(s,start,i)){
                temp.push_back(s.substr(start,i-start+1));
                backtrack(res,temp,s,i+1);
                temp.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int start, int end){
        while(start<end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
};