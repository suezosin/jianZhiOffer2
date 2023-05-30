//
// Created by 23116 on 2023/05/04.
//
class Solution {
public:
    bool validPalindrome(string s) {
        int left=0;
        int right=s.size()-1;
        while(left<=right) {
            if (left == right) return true;
            //s由小写字母组成
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                //如果s[left]和s[right]不相等，那么就删除s[left]或s[right]，然后判断剩下的字符串是否为回文串
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
        }
        return true;
    }

    bool isPalindrome(string s, int start, int end) {
//        int left=0;
//        int right=s.size()-1;
        while(start<=end){
            if(start==end) return true;
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};