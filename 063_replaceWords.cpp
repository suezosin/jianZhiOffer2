class Solution {
public:
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
    string replaceWords(vector<string>& dictionary, string sentence) {
        //思路：使用trie树，将单词插入trie树，然后遍历句子，找到最短的前缀
        root = new TrieNode();
        for(int i=0;i<dictionary.size();i++){
            insert(dictionary[i]);
        }
        string res;
        int start=0;
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' '){
                res += replace(sentence.substr(start,i-start));
                res += ' ';
                start = i+1;
            }
        }
        res += replace(sentence.substr(start,sentence.size()-start));
        return res;
    }
    void insert(string word){
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
    string replace(string word){
        TrieNode* cur=root;
        string res;
        for(int i=0;i<word.size();i++){
            int index = word[i] - 'a';
            if(cur->children[index]==nullptr){
                return word;
            }
            res += word[i];
            if(cur->children[index]->isWord){
                return res;
            }
            cur = cur->children[index];
        }
        return word;
    }
};