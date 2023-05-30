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
    int maxPathSum(TreeNode* root) {
        //节点之和最大的路径
        //思路：dfs，每次返回当前节点的值加上左右子树中的最大值，如果左右子树中的最大值小于0，则不加上左右子树中的最大值
        int res=INT_MIN;
        dfs(root,res);
        return res;
    }
    int dfs(TreeNode* root, int& res){
        if(root==nullptr) return 0;
        int left = max(0,dfs(root->left,res));
        int right = max(0,dfs(root->right,res));
        res = max(res,root->val+left+right);
        return root->val+max(left,right); //这句话的意思是：返回当前节点的值加上左右子树中的最大值
    }
};