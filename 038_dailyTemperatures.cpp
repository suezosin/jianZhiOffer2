class Solution {
public:
    //思路：用栈来实现,温度递减的时候，将下标压入栈中，温度递增的时候，弹出栈顶元素，计算下标差值
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> res;
        for(int i=0;i<temperatures.size();++i){
            while(!s.empty()){
                if(temperatures[i]>temperatures[s.top()]){
                    res[s.top()]=i-s.top();
                    s.pop();
                }
                else break;
            }
            s.push(i);
            res.push_back(0);
        }
        return res;
    }
};