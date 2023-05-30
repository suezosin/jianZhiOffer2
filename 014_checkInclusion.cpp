class Solution {
public:
    //思路：双指针加哈希表
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> m;
        for(int i=0;i<s1.size();++i){
            m[s1[i]]++;
        }
        int left=0;
        int right=s1.size()-1;
        if(right>=s2.size()){
            return false;
        }
        while(right<s2.size()){
            unordered_map<char,int> m2=m;
            bool flag=true;
            for(int i=left;i<=right;++i){
                //若s2[i]不在m中，则返回false直接跳出循环
                if(m2.find(s2[i])==m2.end()){
                    flag=false;
                    break;
                }
                else{
                    m2[s2[i]]--;
                    if(m2[s2[i]]<0){
                        flag=false;
                        break;
                    }
                }
            }
            //即使s2[i]在m中，但是s2[i]的个数大于m中s2[i]的个数，也返回false
            if(flag){
                return true;
            }
            left++;
            right++;
        }
        return false;
    }
};