class Solution {
public:
    // 1. sort the intervals by the start time
    // 2. merge the intervals
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1) return intervals;
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            return a[0]<b[0];
        }); //这句话的意思是，按照每个vector的第一个元素从小到大排序
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=res.back()[1]){
                res.back()[1] = max(res.back()[1],intervals[i][1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};