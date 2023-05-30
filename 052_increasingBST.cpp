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
    //展平二叉搜索树
    //思路：中序遍历，将节点的左子树置空，将节点的右子树指向下一个节点
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(-1);
        TreeNode* cur = dummy;
        inorder(root,cur);
        return dummy->right;
    }
    void inorder(TreeNode* root, TreeNode*& cur){
        if(root==nullptr) return;
        inorder(root->left,cur);
        root->left=nullptr;
        cur->right=root;
        cur=root;
        inorder(root->right,cur);
    }
};