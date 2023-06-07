//首先按照从上到下、从左到右的顺序输入一棵满二叉树中每一个结点对应的权重，例如输入1、1、2表示二叉树的根结点的权重为1，它的左、右两个子节点的权重分别为1和2。
//
//然后判断该满二叉树中是否存在这样的非叶子结点：它的左子树上所有结点的权重之和等于右子树上所有结点的权重之和。
//
//现在给你一棵满二叉树的所有结点的权重，请编写一个程序，寻找是否存在满足要求的非叶子结点，如果存在输出“Yes”，否则输出“No”。
#include<iostream>
#include<vector>
using namespace std;

class fullBinaryTree{
public:
    class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    };
    TreeNode* root;
    bool isExist(TreeNode* root){
        if(root==nullptr) return false;
        if(root->left==nullptr&&root->right==nullptr) return false;
        if(root->left==nullptr&&root->right!=nullptr) return false;
        if(root->left!=nullptr&&root->right==nullptr) return false;
        int leftSum = getSum(root->left);
        int rightSum = getSum(root->right);
        if(leftSum==rightSum) return true;
        else return false;
    }
    int getSum(TreeNode* root){
        if(root==nullptr) return 0;
        return root->val+getSum(root->left)+getSum(root->right);
    }
    TreeNode* buildTree(vector<int>& nums,int index){
        if(index>=nums.size()) return nullptr;
        TreeNode* root = new TreeNode(nums[index]);
        root->left = buildTree(nums,2*index+1);
        root->right = buildTree(nums,2*index+2);
        return root;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    fullBinaryTree fbt;
    fbt.root = fbt.buildTree(nums,0);
    if(fbt.isExist(fbt.root)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}