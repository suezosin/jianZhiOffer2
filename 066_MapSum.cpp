class MapSum {
public:
    /** Initialize your data structure here. */
    class TrieNode{
    public:
        TrieNode* children[26];
        int val;
        TrieNode(){
            for(int i=0;i<26;i++){
                children[i]=nullptr;
            }
            val=0;
        }
    };
    TrieNode* root;
    MapSum() {
        root = new TrieNode();
    }

    void insert(string key, int val) {
        TrieNode* cur = root;
        int index;
        for(int i=0;i<key.size();i++){
            index = key[i]-'a';
            if(cur->children[index]==nullptr){
                cur->children[index] = new TrieNode();
            }
            cur = cur->children[index];
        }
        cur->val = val;
    }

    int sum(string prefix) {
        TrieNode* cur = root;
        int index;
        for(int i=0;i<prefix.size();i++){
            index = prefix[i]-'a';
            if(cur->children[index]==nullptr){
                return 0;
            }
            cur = cur->children[index];
        }
        return dfs(cur);
    }
    int dfs(TrieNode* cur){
        int sum = cur->val;
        for(int i=0;i<26;i++){
            if(cur->children[i]!=nullptr){
                sum+=dfs(cur->children[i]);
            }
        }
        return sum;
    }

};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */