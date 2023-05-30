//
// Created by 23116 on 2023/05/12.
//
//外星人词典
//思路：对每个词排序，然后作为key，放入map，最后判断是否有序
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int *map=new int[26]; //新建map
        for(int i=0; i<order.size(); ++i){
            map[order[i]-'a']=i; //将order中的字符映射到map中
        }
        //遍历words
        for(int i=0; i<words.size()-1;++i){
            string s1=words[i]; //取出第i个词
            string s2=words[i+1]; //取出第i+1个词
            //遍历两个词,找到第一个不符合排序的字符
            int j=0;
            for(;j<s1.size()&&j<s2.size();++j){
                if(map[s1[j]-'a']>map[s2[j]-'a']) return false;
                else if(map[s1[j]-'a']<map[s2[j]-'a']) break;
            }
            //如果第一个词的长度大于第二个词的长度，且第二个词的前j个字符都相等，则返回false
            if(j==s2.size()&&j<s1.size()) return false;
        }
        return true;
    }
};