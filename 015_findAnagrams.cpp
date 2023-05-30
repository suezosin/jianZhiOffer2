//
// Created by 23116 on 2023/05/04.
//
//class Solution {
//public:
//    //思路：滑动窗口，先统计p中每个字符出现的次数，然后遍历s，如果s中的字符在p中出现，那么就将该字符出现的次数减1，如果s中的字符不在p中出现，那么就将该字符出现的次数加1，如果s中的字符在p中出现，且该字符出现的次数大于0，那么就将count加1，如果s中的字符在p中出现，且该字符出现的次数小于等于0，那么就将count减1，如果count等于p的长度，那么就将当前索引减去p的长度加1，然后将该索引加入res中
//    vector<int> findAnagrams(string s, string p) {
//        vector<int> res;
//        unordered_map<char,int> m;
//        for(int i=0;i<p.size();++i){
//            m[p[i]]++;
//        }
//        int left=0,right=p.size()-1;
//        if(s.size()<p.size()) return res;
//        while(right<s.size()){
//            unordered_map<char,int> m1;
//            for(int i=left;i<=right;++i){
//                m1[s[i]]++;
//            }
//            if(m1==m)  res.push_back(left);
//            right++;
//            left++;
//        }
//        return res;
//    }
//};
//比较次数过多导致超时，所以需要优化
class Solution {
public:
    //思路：滑动窗口，先统计p中每个字符出现的次数，然后遍历s，如果s中的字符在p中出现，那么就将该字符出现的次数减1，如果s中的字符不在p中出现，那么就将该字符出现的次数加1，如果s中的字符在p中出现，且该字符出现的次数大于0，那么就将count加1，如果s中的字符在p中出现，且该字符出现的次数小于等于0，那么就将count减1，如果count等于p的长度，那么就将当前索引减去p的长度加1，然后将该索引加入res中
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char,int> m;
        int count=0;
        for(int i=0;i<p.size();++i){
            m[p[i]]++;
            count++;
        }
        int left=0,right=p.size()-1;
        if(s.size()<p.size()) return res;

        while(right<s.size()){
            if(left==0){
                for(int i=left;i<=right;++i){
                    if(m.find(s[i])!=m.end()){
                        m[s[i]]--;
                        if(m[s[i]]>=0) count--;
                        else{
                            count++;
                        }
                    }
                    else{
                        m[s[i]]--;
                        count++;
                    }
                }
                if(count==0) res.push_back(left);
                right++;
                left++;
            }
            else{
                m[s[left-1]]++;
                if(m[s[left-1]]>0) count++;
                else{
                    count--;
                }
                m[s[right]]--;
                if(m[s[right]]>=0) count--;
                else{
                    count++;
                }
                if(count==0) res.push_back(left);
                right++;
                left++;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
        vector<int> v;
        if(s2.length()<s1.length()) return v;
        int m1[26]={0},m2[26]={0};
        int i=0,j=s1.length(),p,e=0,c;
        for(char c:s1) m1[c-'a']++;
        for(p=i;p<j;p++) m2[s2[p]-'a']++;
        for(p=0;p<26;p++) if(m2[p]==m1[p]) e++;
        if(e==26) v.push_back(i);
        while(j<s2.length()){
            c=s2[i]-'a';
            if(m2[c]==m1[c]) e--;
            m2[c]--;
            if(m2[c]==m1[c]) e++;
            i++;
            c=s2[j]-'a';
            if(m2[c]==m1[c]) e--;
            m2[c]++;
            if(m2[c]==m1[c]) e++;
            j++;
            // cout<<e<<endl;
            if(e==26) v.push_back(i);
        }
        return v;
    }
};