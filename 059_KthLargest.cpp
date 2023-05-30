class KthLargest {
public:
    //数据流中的第K大元素
    //思路：用一个最小堆来存储前k大的元素，然后每次添加元素时，如果堆的大小小于k，则直接将元素添加到堆中，否则将元素与堆顶元素比较，如果元素大于堆顶元素，则将堆顶元素弹出，然后将元素添加到堆中
    //这样，堆顶元素就是第k大的元素
    //注意：这里使用最小堆，因为我们要找的是第k大的元素，如果使用最大堆，那么堆顶元素就是第k小的元素
    //时间复杂度：O(nlogk)
    //空间复杂度：O(k)
    //c++堆，priority_queue，默认是最大堆，如果要使用最小堆，需要加上greater<int>
    priority_queue<int,vector<int>,greater<int>> pq;
    int size;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(int i=0;i<nums.size();i++){
            add(nums[i]);
        }
    }

    int add(int val) {
        //方法1：使用最小堆
        if(pq.size()<size){
            pq.push(val);
        }
        else if(val>pq.top()){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */