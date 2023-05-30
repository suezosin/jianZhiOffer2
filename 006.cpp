//
// Created by 23116 on 2023/5/2.
//
class Solution {
public:
//    vector<int> twoSum(vector<int>& numbers, int target) {
//        //暴力解法
//        vector<int> res;
//        for(int i=0; i<numbers.size();i++){
//            for(int j=0; j<numbers.size();j++){
//                if(numbers[i]+numbers[j]==target){
//                    if(i!=j){
//                        res.push_back(i); //push_back()函数是在vector的尾部添加一个元素，与python中的append()函数类似
//                        res.push_back(j);
//                        return res;
//                    }
//
//                }
//            }
//        }
//        return res;
//    }
    //二分查找优化，即用二分查找值为target-numbers[i]的下标
//    vector<int> twoSum(vector<int>& numbers, int target) {
//        vector<int> res;
//        for(int i=0; i<numbers.size();i++){
//            int left=i+1;
//            int right=numbers.size()-1;
//            while(left<=right){ // 二分查找的终止条件是left>right
//                int mid=(left+right)/2; //mid的值是left和right的中间值
//                if(numbers[i]+numbers[mid]==target){
//                    res.push_back(i);
//                    res.push_back(mid);
//                    return res;
//                }
//                else if(numbers[i]+numbers[mid]<target){
//                    left=mid+1; //如果numbers[i]+numbers[mid]<target，则说明target在mid的右边，所以left=mid+1
//                }
//                else{
//                    right=mid-1; //如果numbers[i]+numbers[mid]>target，则说明target在mid的左边，所以right=mid-1
//                }
//            }
//        }
//        return res;
//    }
//    //哈希表优化
//    vector<int> twoSum(vector<int>& numbers, int target) {
//        vector<int> res;
//        unordered_map<int,int> m; //unordered_map是哈希表，unordered_map<int,int> m;表示m是一个哈希表，key是int类型，value也是int类型
//        for(int i=0; i<numbers.size();i++){
//            if(m.find(target-numbers[i])!=m.end()){ //如果target-numbers[i]在哈希表中，则返回target-numbers[i]的下标
//                res.push_back(m[target-numbers[i]]);
//                res.push_back(i);
//                return res;
//            }
//            m[numbers[i]]=i; //如果target-numbers[i]不在哈希表中，则将numbers[i]的值作为key，i作为value存入哈希表中
//        }
//        return res;
//    }
    //双指针法
    vector<int> twoSum(vector<int>& numbers, int target){
        vector<int> res;
        int left=0; //left指针指向数组的第一个元素
        int right=numbers.size()-1; //right指针指向数组的最后一个元素
        while(left<right){
            //如果numbers[left]+numbers[right]==target，则将left和right的值存入res中
            if(numbers[left]+numbers[right]==target){
                res.push_back(left);
                res.push_back(right);
                return res;
            }
            //如果numbers[left]+numbers[right]<target，则说明target在right的左边，所以left=left+1
            else if(numbers[left]+numbers[right]<target){
                left=left+1;
            }
            else{
                right=right-1; //如果numbers[left]+numbers[right]>target，则说明target在left的右边，所以right=right-1
            }
        }
}
};