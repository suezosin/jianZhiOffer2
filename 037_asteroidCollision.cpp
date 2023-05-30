class Solution {
public:
    //思路：用栈来实现,遇到负数时，判断栈顶元素是否为正数，如果是，则比较两者的绝对值，如果栈顶元素的绝对值大，则弹出栈顶元素，否则弹出当前元素
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;//新建栈
        for(int i=0; i<asteroids.size();++i){
            if(asteroids[i]>0) s.push(asteroids[i]); //如果当前元素为正数，则压入栈中
            else{
                while(!s.empty()&&s.top()>0&&s.top()<-asteroids[i]){
                    s.pop();
                }
                //如果栈为空，或者栈顶元素为负数，则将当前元素压入栈中
                if(s.empty()||s.top()<0) s.push(asteroids[i]);
                //如果栈顶元素的绝对值和当前元素的绝对值相等，则弹出栈顶元素
                else if(s.top()==-asteroids[i]) s.pop();
            }
        }
        vector<int> res;
//        while(!s.empty()){
//            res.push_back(s.top());  //
//            s.pop(); //弹出栈顶元素
//        }
        while(!s.empty()){
            res.insert(res.begin(), s.top());  //将栈中元素插入到res的头部
            s.pop(); //弹出栈顶元素
        }
        return res;
    }
};