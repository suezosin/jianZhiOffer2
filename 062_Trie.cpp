class Trie {
public:
    class TrieNode{
    public:
        TrieNode* children[26];
        bool isWord;
        TrieNode(){
            for(int i=0;i<26;i++){
                children[i]= nullptr;
            }
            isWord = false;
        }
    };
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        //思路：遍历字符串，如果当前节点的子节点为空，则创建一个新的节点
        //如果当前节点的子节点不为空，则继续遍历
        TrieNode* cur=root;
        for(int i=0;i<word.size();i++){
            int index = word[i]-'a';
            if(cur->children[index]==nullptr){
                cur->children[index]=new TrieNode();
            }
            cur = cur->children[index];
        }
        cur->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur=root;
        for(int i=0;i<word.size();i++){
            int index = word[i] - 'a';
            if(cur->children[index]==nullptr){
                return false;
            }
            cur = cur->children[index];
        }
        return cur->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur=root;
        for(int i=0;i<prefix.size();i++){
            int index = prefix[i] - 'a';
            if(cur->children[index]==nullptr){
                return false;
            }
            cur = cur->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */