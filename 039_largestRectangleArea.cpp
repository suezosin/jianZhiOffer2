class Solution {
public:
    //蛮力法：对每个柱子，向左右两边扩展，直到遇到比当前柱子矮的柱子，计算面积，取最大值
//    int largestRectangleArea(vector<int>& heights) {
//        int res=0;
//        for(int i=0;i<heights.size();++i){
//            int left=i-1;
//            int right=i+1;
//            while(left>=0&&heights[left]>=heights[i]) --left;
//            while(right<heights.size()&&heights[right]>=heights[i]) ++right;
//            res=max(res, (right-left-1)*heights[i]);
//        }
//        return res;
//    }
    //分治法：找到最小的柱子，然后分别计算左边和右边的最大面积，取最大值
//    int largestRectangleArea(vector<int>& heights) {
//        return largestRectangleArea(heights, 0, heights.size()-1);
//    }
//    int largestRectangleArea(vector<int>& heights, int left, int right){
//        if(left>right) return 0;
//        int minIndex=left;
//        for(int i=left;i<=right;++i){
//            if(heights[minIndex]>heights[i]) minIndex=i;
//        }
//        return max((right-left+1)*heights[minIndex], max(largestRectangleArea(heights, left, minIndex-1), largestRectangleArea(heights, minIndex+1, right)));
//    }
    //栈：遍历数组，如果当前柱子高度大于栈顶元素，则将当前柱子的下标压入栈中，否则，弹出栈顶元素，计算面积，取最大值
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);//为了让所有元素都能弹出栈，将最后一个元素设为0
        int maxArea = 0;
        for(int i=0; i<heights.size(); ++i){
            while(!s.empty()&&heights[i]<heights[s.top()]){
                int cur=s.top();
                s.pop();
                maxArea = max(maxArea, heights[cur]*(s.empty()?i:i-s.top()-1));
            }
            s.push(i);
        }
        return maxArea;
    }
};