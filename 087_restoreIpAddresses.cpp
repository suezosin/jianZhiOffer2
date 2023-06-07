class Solution {
public:
    //复原IP地址，给定一个只包含数字的字符串，复原它并返回所有可能的IP地址格式
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string temp;
        backtrack(res,temp,s,0,0); //count记录当前已经有几个数字了,point记录当前已经有几个点了
        return res;
    }

    void backtrack(vector<string>& res, string temp, string s, int count, int point){
        if(count==4){
            if(point==s.size()) res.push_back(temp.substr(0,temp.size()-1)); //temp最后有一个点，故减1
            return;
        }
        for(int i=1;i<=3;i++){
            if(point+i>s.size()) return; //说明剩下的数字长度不够，故直接返回
            string str=s.substr(point,i);
            if(i>1&&str[0]=='0') return; //说明该数字不是0开头，故直接返回
            if(stoi(str)>255) return; //说明该数字大于255，故直接返回
            temp+=str+".";
            backtrack(res,temp,s,count+1,point+i);
            temp=temp.substr(0,temp.size()-i-1); //temp最后有一个点，故减1
        }
    }
};