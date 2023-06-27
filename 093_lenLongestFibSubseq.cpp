class Solution {
public:
    //最长的斐波那契子序列的长度
    //思路：动态规划，dp[i][j]表示以arr[i]和arr[j]结尾的最长的斐波那契子序列的长度
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        //初始化
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j] = 2;
            }
        }
        //状态转移方程
        int res=0;
        for(int i=2;i<n;i++){
            int l=0,r=i-1;//l和r分别表示斐波那契子序列的前两个数的下标
            while(l<r){
                if(arr[l]+arr[r]<arr[i]){
                    l++;
                }else if(arr[l]+arr[r]>arr[i]){
                    r--;
                }else{ //arr[l]+arr[r]==arr[i]
                    dp[r][i] = max(dp[r][i],dp[l][r]+1);
                    res = max(res,dp[r][i]);
                    l++; //这里l++和r--都可以，因为arr[l]+arr[r]==arr[i]，所以l和r都可以向后移动
                    r--;
                }
            }
        }
        return res==2?0:res;
    }
};