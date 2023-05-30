/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //思路：前序遍历，将节点的值转换为字符串，如果节点为空，则转换为"null"
        if(root== nullptr) return "null";
        string res = to_string(root->val);
        res += "," + serialize(root->left);
        res += "," + serialize(root->right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //思路：前序遍历，将字符串转换为节点的值，如果是"null"，则转换为空
        queue<string> q; //这里要用queue，不能用stack，因为queue是先进先出，而stack是先进后出，这里要用先序遍历，所以要用queue
        string temp;
        for(auto ch:data){ //这里要用auto，不能用char，否则会报错,因为data是string类型,而不是char类型,所以要用auto,或者用string,这句代码的意思是遍历data中的每一个字符
            if(ch==','){
                q.push(temp); //将temp放入队列中
                temp.clear(); //清空temp
            }
            else temp += ch; //将ch放入temp中
        }
        if(!temp.empty()) q.push(temp);
        return deserialize(q);
    }
    TreeNode* deserialize(queue<string>& q) {
        //思路：前序遍历，将字符串转换为节点的值，如果是"null"，则转换为空
        if(q.empty()) return nullptr;
        string val = q.front();
        q.pop();
        if(val=="null") return nullptr;
        TreeNode* root = new TreeNode(stoi(val)); //将字符串转换为int
        root->left = deserialize(q); //递归,将q传入,因为q是引用,所以不会改变q的值
        root->right = deserialize(q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));