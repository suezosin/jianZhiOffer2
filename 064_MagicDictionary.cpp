class MagicDictionary {
public:
    /** Initialize your data structure here. */
    class TrieNode{
    public:
        TrieNode* children[26];
        bool isWord;
        TrieNode(){
            for(int i=0;i<26;i++){
                children[i]=nullptr;
            }
            isWord=false;
        }
    };
    TrieNode* root;
    MagicDictionary() {
        root = new TrieNode();
    }

    void buildDict(vector<string> dictionary) {
        for(int j=0;j<dictionary.size();j++){
            TrieNode* cur=root;
            string word = dictionary[j];
            for(int i=0;i<word.size();i++){
                int index = word[i]-'a';
                if(cur->children[index]==nullptr){
                    cur->children[index]=new TrieNode();
                }
                cur = cur->children[index];
            }
            cur->isWord = true;
        }
    }
    bool search(string searchWord) {
        return dfs(searchWord,0,root,false);
    }
    bool dfs(string& word,int index,TrieNode* cur,bool isChanged){
        if(index==word.size()){
            return cur->isWord && isChanged;
        }
        int i  = word[index]-'a';
        if(cur->children[i]!=nullptr){
            if(dfs(word,index+1,cur->children[i],isChanged)){
                return true;
            }
        }
        if(!isChanged){
            for(int j=0;j<26;j++){
                if(j==i) continue;
                if(cur->children[j]!=nullptr){
                    if(dfs(word,index+1,cur->children[j],true)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */