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
    int findBottomLeftValue(TreeNode* root) {
        int bottomLeft = 0;
//        if(root==nullptr) return res;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        while(!q1.empty()) {
            TreeNode* cur=q1.front(); //取出当前节点
            bottomLeft = cur->val;
            while(!q1.empty()){
                TreeNode* cur=q1.front(); //取出当前节点
                q1.pop();
                if(cur->left!=nullptr) q2.push(cur->left); //将下一层的节点放入q2中
                if(cur->right!=nullptr) q2.push(cur->right); //将下一层的节点放入q2中
            }
            swap(q1,q2);
        }
        return bottomLeft;
    }
};