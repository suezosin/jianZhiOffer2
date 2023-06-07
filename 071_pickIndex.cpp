class Solution {
public:
    vector<int> sums;
    int total;
    Solution(vector<int>& w) {
        total=0;
        for(int i=0;i<w.size();i++){
            total+=w[i];
            sums.push_back(total);
        }
    }

    int pickIndex() {
        int target = rand()%total;
        int left=0,right=sums.size()-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(sums[mid]>target){
                if(mid==0||sums[mid-1]<=target) return mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */