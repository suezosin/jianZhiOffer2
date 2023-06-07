#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //思路：回溯法，每次递归都有两种选择，选或者不选,数组中的元素互不相同
//    输入：nums = [1,2,3]
//    输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(res,temp,nums,0);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int start){
        res.push_back(temp);
        //输出当前结果,用于调试,可删除
        for(int i=start;i<nums.size();i++){//从start开始,避免重复
            cout<<"i="<<i<<endl;
            temp.push_back(nums[i]);//选nums[i],加入temp,下一次递归从i+1开始
            for(int j=0;j<temp.size();j++){
                cout<<temp[j]<<" ";
            }
            cout<<"test"<<endl;
            backtrack(res,temp,nums,i+1);//递归,选nums[i],下一次递归从i+1开始,避免重复,因为数组中的元素互不相同,所以不会重复,如果有重复元素,则需要先排序,然后判断nums[i]==nums[i-1]是否相等,相等则跳过,不相等则继续递归
            temp.pop_back();//回溯,不选nums[i]
            for(int j=0;j<temp.size();j++){
                cout<<temp[j]<<" ";
            }
            cout<<"test1"<<endl;
        }
    }
};

int main(){
    vector<int> nums={1,2,3};
    Solution s;
    vector<vector<int>> res=s.subsets(nums);
//    for(int i=0;i<res.size();i++){
//        for(int j=0;j<res[i].size();j++){
//            cout<<res[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    return 0;
}