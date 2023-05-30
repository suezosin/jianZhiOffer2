class Solution {
public:
    //思路：将每个时间转换成分钟，然后排序，最后找出最小的差值
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        for(int i=0; i<timePoints.size();++i){
            int h=stoi(timePoints[i].substr(0,2));
            int m=stoi(timePoints[i].substr(3,2));
            times.push_back(h*60+m);
        }
        sort(times.begin(), times.end());
        int res=INT_MAX;
        for(int i=1; i<times.size();++i){
            res=min(res, times[i]-times[i-1]);
        }
        res=min(res, times[0]+24*60-times[times.size()-1]);
        return res;
    }
};