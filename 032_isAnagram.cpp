//
// Created by 23116 on 2023/05/12.
//
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s==t) return false;
        if(s.size() != t.size()) return false;
        int *counts = new int[26];
        for(int i=0; i<26; ++i){
            counts[i]=0;
        }
        for(int i=0; i<s.size();++i){
            counts[s[i]-'a']++;
        }
        for(int i=0; i<t.size();++i){
            if(counts[t[i]-'a']==0) return false;
            counts[t[i]-'a']--;
        }
        return true;
    }
};