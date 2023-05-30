//
// Created by 23116 on 2023/05/04.
//
class Solution {
public:
//思路：遍历字符串，以每个字符为中心，向两边扩展，如果扩展的子串是回文串，那么就将count加1
    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.size();++i){
            count+=countPalindrome(s,i,i);//以s[i]为中心，向两边扩展
            count+=countPalindrome(s,i,i+1);//以s[i]和s[i+1]为中心，向两边扩展
        }
        return count;
    }

    int countPalindrome(string s,int left,int right){
        int count=0;
        while(left>=0&&right<s.size()&&s[left]==s[right]){
            count++;
            left--;
            right++;
        }
        return count;
    }
};