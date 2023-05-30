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
    //将二叉搜索树转换为累加树
    //思路：反向中序遍历，每次将当前节点的值加上上一个节点的值
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        dfs(root,sum);
        return root;
    }
    void dfs(TreeNode* root, int& sum){
        if(root==nullptr) return;
        dfs(root->right,sum);
        sum+=root->val;
        root->val=sum;
        dfs(root->left,sum);
    }
};