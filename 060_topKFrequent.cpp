class Solution {
public:
    //前K个高频元素
    //思路：使用哈希表统计每个元素出现的次数，然后使用优先队列，将元素按照出现次数从大到小排序，然后取出前K个元素
//    vector<int> topKFrequent(vector<int>& nums, int k) {
//        unordered_map<int,int> m;
//        for(int i=0;i<nums.size();i++){
//            m[nums[i]]++;
//        }
//        priority_queue<pair<int,int>> pq;
//        for(auto it=m.begin();it!=m.end();it++){//auto自动推导类型
//            pq.push(make_pair(it->second,it->first));
//        }
//        vector<int> res;
//        for(int i=0;i<k;i++){
//            res.push_back(pq.top().second);
//            pq.pop();
//        }
//        return res;
//    }
    //方法2：使用最小堆
    //思路：使用哈希表统计每个元素出现的次数，然后使用最小堆，将元素按照出现次数从小到大排序，然后取出前K个元素4
    //时间复杂度：O(nlogk)
    //空间复杂度：O(n)
    vector<int> topKFrequent(vector<int>& nums, int k){
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto it=m.begin(); it!=m.end(); it++){
            pq.push(make_pair(it->second,it->first));
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};