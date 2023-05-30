/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //向下的路径节点之和等于targetSum的路径数
    //思路：dfs+前缀和
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long int,long long int> preSum;
        preSum[0]=1;
        return dfs(root,preSum,0,targetSum);
    }
    int dfs(TreeNode* root, unordered_map<long long int,long long int>& preSum, long long int curSum, long long int targetSum){
        if(root==nullptr) return 0;
        long long int res = 0;
        curSum += root->val;
        res += preSum[curSum-targetSum]; //这句话的意思是：如果当前节点的值等于targetSum，那么res加上preSum[0]，即加上1
        preSum[curSum]++; //这句话的意思是：将当前节点的值加入到前缀和中
        res += dfs(root->left,preSum,curSum,targetSum);
        res += dfs(root->right,preSum,curSum,targetSum);
        preSum[curSum]--;
        return res;
    }
};