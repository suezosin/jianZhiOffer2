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
class CBTInserter {
public:
    TreeNode* root;
    CBTInserter(TreeNode* root) {
        this->root=root;
    }

    int insert(int v) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            if(cur->left==nullptr){
                cur->left=new TreeNode(v);
                return cur->val;
            }
            else if(cur->right==nullptr){
                cur->right=new TreeNode(v);
                return cur->val;
            }
            else{
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return -1;
    }

    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */