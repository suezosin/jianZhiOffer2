/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //二叉搜索树中的中序后继节点
    //思路：如果当前节点的值大于p的值，则当前节点有可能是p的后继节点，所以将当前节点赋值给res，然后继续遍历左子树，如果当前节点的值小于等于p的值，则继续遍历右子树
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root==nullptr) return nullptr;
        TreeNode* res =nullptr;
        while(root!=nullptr){
            if(root->val>p->val){
                res = root;
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        return res;
    }
};