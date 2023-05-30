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
    vector<int> largestValues(TreeNode* root) {
        //思路：层序遍历，每层找到最大值
        vector<int> res;
        if(root==nullptr) return res;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        while(!q1.empty()){
            int maxVal=INT_MIN; //每层的最大值
            while(!q1.empty()){
                TreeNode* cur=q1.front(); //取出当前节点
                q1.pop(); //将当前节点弹出
                maxVal=max(maxVal, cur->val); //找到每层的最大值
                if(cur->left!=nullptr) q2.push(cur->left); //将下一层的节点放入q2中
                if(cur->right!=nullptr) q2.push(cur->right); //将下一层的节点放入q2中
            }
            res.push_back(maxVal); //将每层的最大值放入res中
            swap(q1, q2); //swap()交换两个队列
        }
        return res;

    }
};