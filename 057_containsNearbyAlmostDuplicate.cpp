class Solution {
public:
//    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
//        //方法1：暴力法，超时
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size()&&j<=i+k;j++){
//                 if(abs(((long long)nums[i]-(long long)nums[j]))<=(long long)t){
//                     return true;
//                 }
//             }
//         }
//         return false;

        //方法2：桶排序
        //思路：将数组分成t+1个桶，每个桶的大小为t，如果两个数的差值小于等于t，那么这两个数必定在同一个桶中
        //如果两个数的差值大于t，那么这两个数必定不在同一个桶中
        bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
            if(t<0) return false;
            unordered_map<long long int,long long int> buckets;
            long long int w = (long long)t+1;
            for(int i=0;i<nums.size();i++){
                long long int id = getID(nums[i],w);
                if(buckets.count(id)>0){
                    return true;
                }
                if(buckets.count(id-1)>0&&abs(nums[i]-buckets[id-1])<=t){
                    return true;
                }
                if(buckets.count(id+1)>0&&abs(nums[i]-buckets[id+1])<=t){
                    return true;
                }
                buckets[id]=nums[i];
                if(i>=k){
                    buckets.erase(getID(nums[i-k],w));
                }
            }
            return false;
        }
        long long int getID(long long int x, long long int w) {
            return x < 0 ? (x + 1) / w - 1 : x / w;
        }
};