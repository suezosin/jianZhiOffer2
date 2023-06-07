//
// Created by 23116 on 2023/05/30.
//
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        //思路：使用优先队列，每次取出最小的元素，然后将其相邻的元素加入队列
        //注意：优先队列中存储的是pair，pair的第一个元素是nums1中的元素，第二个元素是nums2中的元素
        //时间复杂度：O(klogk)
        //空间复杂度：O(k)
        vector<vector<int>> res;
        if(nums1.empty()||nums2.empty()||k<=0) return res;
        auto cmp = [&nums1,&nums2](pair<int,int> a,pair<int,int> b){//auto自动推导类型,lambda表达式,
            return nums1[a.first]+nums2[a.second]>nums1[b.first]+nums2[b.second];
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        pq.push(make_pair(0,0));
        while(k>0&&!pq.empty()){
            auto cur=pq.top();
            pq.pop();
            res.push_back({nums1[cur.first],nums2[cur.second]});
            if(cur.first+1<nums1.size()){
                pq.push(make_pair(cur.first+1,cur.second));
            }
            if(cur.first==0&&cur.second+1<nums2.size()){ //这里需要注意，只有当cur.first==0时，才能将cur.second+1加入队列,否则会出现重复
                pq.push(make_pair(cur.first,cur.second+1));
            }
            k--;
        }
        return res;
    }


};
