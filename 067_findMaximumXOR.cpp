class Solution {
public:
    class TrieNode{
    public:
        TrieNode* children[2];
        TrieNode(){
            for(int i=0;i<2;i++){
                children[i]=nullptr;
            }
        }
    };
    TrieNode* root;
    TrieNode* buildTrie(vector<int>& nums){
        root = new TrieNode();
        for(int i=0;i<nums.size();i++){
            TrieNode* cur = root;
            for(int j=31;j>=0;j--){
                int index = (nums[i]>>j)&1;//从高位到低位,注意这里的写法,不是nums[i]>>j-1,而是nums[i]>>j,因为>>的优先级比-低,所以要加括号,否则会出错,这里是一个坑
                if(cur->children[index]==nullptr){
                    cur->children[index]=new TrieNode();
                }
                cur=cur->children[index];
            }
        }
        return root;
    }
    int findMaximumXOR(vector<int>& nums) {
        root = buildTrie(nums);
        int res = 0;
        for(int i=0; i<nums.size();i++){
            TrieNode* cur=root;
            int xorVal =0;
            for(int j=31;j>=0;j--){
                int bit  =(nums[i]>>j)&1;
                if(cur->children[bit^1]!=nullptr){
                    xorVal = (xorVal<<1) + 1;
                    cur = cur->children[bit^1];
                }
                else{
                    xorVal = xorVal<<1;
                    cur = cur->children[bit];
                }
            }
            res = max(res,xorVal);
        }
        return res;
    }
};