class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return x;
        int left=0,right=x;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(mid==0) return 1;
            if(mid>x/mid){
                if((mid-1)<=x/(mid-1)) return mid-1;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return -1;
    }
};