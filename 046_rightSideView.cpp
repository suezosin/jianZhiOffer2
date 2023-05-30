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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        if(root== nullptr) return res;
        q1.push(root);
        while(!q1.empty()){
            while(!q1.empty()){
                TreeNode* cur=q1.front();
                q1.pop();
                if(q1.empty()) res.push_back(cur->val);
                if(cur->left!= nullptr) q2.push(cur->left);
                if(cur->right!= nullptr) q2.push(cur->right);
            }
            swap(q1,q2);
        }
        return res;
    }
};