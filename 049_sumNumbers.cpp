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
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
    //思路：dfs，每次将当前节点的值乘以10，然后加上当前节点的值，如果当前节点的左右子树都为空，则返回当前节点的值
    int dfs(TreeNode* root, int sum){
        if(root==nullptr) return 0;
        sum = sum*10+root->val;
        if(root->left==nullptr&&root->right==nullptr) return sum;
        return dfs(root->left, sum)+dfs(root->right,sum);
    }
};