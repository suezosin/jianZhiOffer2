class Solution {
public:
    //思路：先遍历arr1，统计每个数字出现的次数，然后遍历arr2，将arr2中出现的数字按照arr2的顺序放入res中，然后将arr1中剩余的数字按照升序放入res中
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int count[1001] = {0};
        for(int i=0;i<arr1.size();i++){
            count[arr1[i]]++;
        }

        int i=0;
        for(int j=0;j<arr2.size();j++){
            while(count[arr2[j]]>0){
                arr1[i++]=arr2[j];
                count[arr2[j]]--;
            }
        }
//        i--;
        for(int j=0;j<1001;j++){
            while(count[j]>0){
                arr1[i++]=j;
                count[j]--;
            }
        }

        return arr1;
    }
};