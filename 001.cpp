//题目描述：
//小明的电脑这几天出了一点问题：在输入英文的时候，有一些单词会莫名其妙地在后面重复一次或多次。 例如：输入“Who are you”，有时候会变成“Who are are you”。 你能否编写一个程序帮助小明去掉那些相邻的、重复出现的单词中的第二个单词？ 注意：
//
//(1) 为了对问题进行简化，在输入数据中均不包含标点符号；
//
//(2) 单词之间统一用一个英文的空格隔开；
//
//(3) 单词不区分大小写，即"Who"和"who"当做同一个单词看待；
//
//(4) 不需要考虑输入数据中本身存在两个单词重复的情况，即只要出现单词重复都需要去掉第二个；
//
//(5) 特别的，对于多个连续出现的重复单词，只需要保留第一个。
//
//
//
//输入描述
//        单组输入。 输入一个长度不超过2000的字符串，该字符串由若干个英文单词和英文空格组成。
//
//输出描述
//        输出按照要求去掉重复单词之后的字符串。
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

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

int main(){
    string sentence;
    getline(cin,sentence);
    Trie* trie = new Trie();
    string word;
    string original;
    string res;
    string lastword;
//    cout<<sentence<<endl;
    for(int i=0;i<sentence.size();i++){
        if(sentence[i]==' '){
            if(!trie->search(word)){
                res+=original;
                lastword = word;
                res+=' ';
                trie->insert(word);
            }
            else{
                if(word!=lastword){
                    res+=original;
                    res+=' ';
                }
            }
            lastword= word;
            word="";
            original="";
        }
        else{
            //大写转小写
            char c = sentence[i];
            if(c>='A'&&c<='Z'){
                c = c-'A'+'a';
            }
            word+=c;
            original+=sentence[i];
        }
    }
    if(!trie->search(word)){
        res+=original;
    }
    else{
        if(word!=lastword){
            res+=original;
        }
    }
    cout<<res<<endl;
    return 0;
}