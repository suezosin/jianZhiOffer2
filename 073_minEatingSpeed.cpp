class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int sum = 0;
        for(int i=0;i<piles.size();i++){
            sum+=piles[i];
        }
        long long int left=1,right=sum;
        while(left<=right){
            long long int mid=left+(right-left)/2;
            if(mid==0) return 1;
            if(getTc(piles,mid)<=h){
                if(getTc(piles,mid-1)>h) return mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return 1;
    }
    int getTc(vector<int>& piles, long long int mid){
        int tc = 0;
        for(int i=0;i<piles.size();i++){
            if(mid!=0){
                if(piles[i]%mid==0) tc+=piles[i]/mid;
                else tc+=piles[i]/mid+1;
            }
        }
        return tc;
    }
};