class Solution {
public:
    //给定一个字符串，将字符串划分为若干个子串，使得每个子串都是回文串，求最小的划分次数
    //思路：动态规划，dp[i]表示前i+1个字符的最小划分次数
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,0);
        //初始化
        for(int i=0;i<n;i++){
            dp[i] = i;
        }
        //预处理，判断s[j,i]是否为回文串
        vector<vector<bool>> isPalindrome(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(s[j]==s[i] && (i-j<=1 || isPalindrome[j+1][i-1])){
                    isPalindrome[j][i] = true;
                }
            }
        }
        //状态转移方程为：dp[i] = min(dp[i],dp[j-1]+1) if s[j,i]是回文串
        for(int i=0;i<n;i++){
            if(isPalindrome[0][i]){
                dp[i] = 0;
            }else{
                for(int j=1;j<=i;j++){
                    if(isPalindrome[j][i]){
                        dp[i] = min(dp[i],dp[j-1]+1);
                    }
                }
            }
        }
        return dp[n-1];
    }

//    bool isPalindrome(string s, int left, int right){
//        while(left<right){
//            if(s[left]!=s[right]) return false;
//            left++;
//            right--;
//        }
//        return true;
//    }
};