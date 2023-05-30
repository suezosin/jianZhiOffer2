//
// Created by 23116 on 2023/05/04.
//
#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left=0;
        int right=s.size()-1;
        while(left<=right){
            if(left==right) return true;
            //如果s[left]不是字母或数字，那么left++
            if(!isalnum(s[left])){
                left++;
                continue;
            }
            //如果s[right]不是字母或数字，那么right--
            if(!isalnum(s[right])){
                right--;
                continue;
            }
            //如果s[left]和s[right]都是字母或数字，且不相等，那么返回false
//            printf("%d\n",abs(s[left]-s[right]));
            if(s[left]!=s[right]&&abs(s[left]-s[right])!=32) return false;
            //必须都为字母或数字，且相等
            //s[left]或s[right]是数字
            else if(s[left]!=s[right] && (isdigit(s[left])||isdigit(s[right]))){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main(){
    string str = "0P";
    Solution s;
    printf("%d\n",s.isPalindrome(str));
    return 0;
}