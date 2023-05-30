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
    //二叉搜索树中的两数之和
    bool findTarget(TreeNode* root, int k) {
        //思路：中序遍历，然后使用双指针
        vector<int> nums;
        inorder(root,nums);
        int left=0,right=nums.size()-1;
        while(left<right){
            int sum = nums[left]+nums[right];
            if(sum==k){
                return true;
            }
            else if(sum<k){
                left++;
            }
            else{
                right--;
            }
        }
        return false;
    }
    void inorder(TreeNode* root, vector<int>& nums){
        if(root==nullptr) return;
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
};