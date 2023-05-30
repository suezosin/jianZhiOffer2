class Solution {
    //思路：用栈来实现
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0; i<tokens.size();++i){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int a=s.top();//取出栈顶元素
                s.pop();//弹出栈顶元素
                int b=s.top();//取出栈顶元素
                s.pop();//弹出栈顶元素
                if(tokens[i]=="+") s.push(a+b);//将运算结果压入栈中
                else if(tokens[i]=="-") s.push(b-a);
                else if(tokens[i]=="*") s.push(a*b);
                else if(tokens[i]=="/") s.push(b/a);
            }
            else{
                s.push(stoi(tokens[i]));//将数字压入栈中
            }
        }
        return s.top();
    }
};