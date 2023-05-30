class Solution {
public:
    //思路：现将矩阵转换为直方图，然后对每一行都进行一次直方图的最大矩形面积计算
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int res=0;
        heights.push_back(0);
        for(int i=0;i<heights.size();++i){
            while(!s.empty()&&heights[i]<heights[s.top()]){
                int cur=s.top();
                s.pop();
                res=max(res, heights[cur]*(s.empty()?i:i-s.top()-1));
            }
            s.push(i);
        }
        return res;
    }
    int maximalRectangle(vector<string>& matrix) {
        if(matrix.empty()) return 0;
        int res=0;
        vector<int> heights(matrix[0].size(), 0);
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                if(matrix[i][j]=='0') heights[j]=0;
                else ++heights[j];
            }
            res=max(res, largestRectangleArea(heights));
        }
        return res;
    }
};