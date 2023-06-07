class Solution {
public:
    //单词的压缩编码
    class TrieNode{
    public:
        TrieNode* children[26];
        bool isWord;
        TrieNode(){
            for(int i=0;i<26;i++){
                children[i]=nullptr;
            }
            isWord = false;
        }
    };
    TrieNode* root;
    TrieNode* buildTrie(vector<string>& words){
        root = new TrieNode();
        for(int i=0;i<words.size();i++){
            TrieNode* cur = root;
            for(int j=words[i].size()-1;j>=0;j--){
                int index = words[i][j]-'a';
                if(cur->children[index]==nullptr){
                    cur->children[index]=new TrieNode();
                }
                cur = cur->children[index];
            }
            cur->isWord = true;
        }
        return root;
    }
    int minimumLengthEncoding(vector<string>& words) {
        root = buildTrie(words);
        int res = 0;
        dfs(root,0,res);
        return res;
    }
    void dfs(TrieNode* cur,int depth,int& res){
        bool isLeaf = true;
        for(int i=0;i<26;i++){
            if(cur->children[i]!=nullptr){
                isLeaf = false;
                dfs(cur->children[i],depth+1,res);
            }
        }
        if(isLeaf){
            res += depth + 1;
        }
    }
};