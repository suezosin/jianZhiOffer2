//
// Created by 23116 on 2023/05/04.
//
class Solution {
public:
    //思路
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        for(int i=0;i<t.size();++i){
            m[t[i]]++;
        }
        int left=0,right=0;
        int count=t.size();
        int minLen=INT_MAX; //注意这里的minLen的初始值要设置为INT_MAX，因为如果设置为0的话，当s的长度为1时，就会返回空字符串
        int start=0;
        //滑动窗口
        while(right<s.size()){
            if(m.find(s[right])!=m.end()){//如果s中的字符在t中出现
                m[s[right]]--;
                if(m[s[right]]>=0) count--; //如果s中的字符在t中出现，且该字符出现的次数大于等于0，那么就将count减1
                while(count==0){//如果count等于0，说明s中的字符在t中都出现了
                    if(right-left+1<minLen){ //如果当前的窗口长度小于minLen，那么就更新minLen和start
                        minLen=right-left+1;
                        start=left;
                    }
                    if(m.find(s[left])!=m.end()){//如果s中的字符在t中出现,那么就将该字符出现的次数加1
                        m[s[left]]++;
                        if(m[s[left]]>0) count++;//如果s中的字符在t中出现，且该字符出现的次数大于0，那么就将count加1
                    }
                    left++;//left向右移动
                }
            }
            right++;//right向右移动
        }
        return minLen==INT_MAX?"":s.substr(start,minLen);
    }
};