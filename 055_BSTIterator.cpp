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
class BSTIterator {
public:
    //二叉搜索树迭代器
    //思路：中序遍历，然后用一个变量记录当前遍历到的位置
//    TreeNode* root;
//    TreeNode* cur;
//    BSTIterator(TreeNode* root) {
//        this->root = root;
//        this->cur = root;
//    }
//
//    int next() {
//        //返回下一个最小的元素
//        int res = 0;
//        while(cur!=nullptr){
//            if(cur->left==nullptr){//左子树为空,则当前节点为最小节点,然后遍历右子树
//                res = cur->val;
//                cur = cur->right;
//                break;
//            }else{//左子树不为空,则找到左子树的最右节点,然后将当前节点赋值给最右节点的右子树,然后遍历左子树
//                TreeNode* pre = cur->left;
//                while(pre->right!=nullptr&&pre->right!=cur){//找到左子树的最右节点
//                    pre = pre->right;
//                }
//                if(pre->right==nullptr){//如果最右节点的右子树为空,则将当前节点赋值给最右节点的右子树,然后遍历左子树
//                    pre->right = cur;
//                    cur = cur->left;
//                }else{ //如果最右节点的右子树不为空,则将最右节点的右子树置为空,然后遍历右子树
//                    res = cur->val;
//                    cur = cur->right;
//                    pre->right = nullptr;
//                    break;
//                }
//            }
//        }
//        return res;
//    }
//
//    bool hasNext() {
//        //是否有下一个最小的元素
//        return cur!=nullptr;
//    }
    //方法二：用栈来实现
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root){
        while(root!=nullptr){
            st.push(root);
            root = root->left;
        }
    }
    int next(){
        TreeNode* cur = st.top();
        st.pop();
        int res = cur->val;
        cur = cur->right;
        while(cur!=nullptr){
            st.push(cur);
            cur = cur->left;
        }
        return res;
    }
    bool hasNext(){
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */