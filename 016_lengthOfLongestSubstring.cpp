class Solution {
public:
    //思路
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int left=0,right=0;
        int res=0;
        int count=0;
        while(right<s.size()){
            if(m.find(s[right])!=m.end()){
                int tmp=m[s[right]];
                for(int i=left;i<=tmp;++i){
                    m.erase(s[i]);
                    count--;
                }
                left=tmp+1;
                m[s[right]]=right;
                count++;
                res=max(res,count);
                right++;
            }
            else{
                m[s[right]]=right;
                count++;
                res=max(res,count);
                right++;
            }
        }
        return res;
    }
};