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
    TreeNode* pruneTree(TreeNode* root) {
        //思路：后序遍历，如果当前节点的左右子树都为空，且当前节点的值为0，则删除当前节点
        if(root== nullptr) return root;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(root->left== nullptr&&root->right== nullptr&&root->val==0){
            return nullptr; //这里不要忘记返回nullptr
        }
        return root; //这里不要忘记返回root
    }
};