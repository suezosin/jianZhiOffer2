//
// Created by 23116 on 2023/05/12.
//
//变位词组,
//思路：对每个词排序，然后作为key，放入map，最后取出所有value
//map的key可以是string，也可以是vector<int>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(int i=0; i<strs.size();++i){
            string s = strs[i]; //取出每个词
            sort(s.begin(), s.end()); //对每个词排序
            map[s].push_back(strs[i]); //将排序后的词作为key，原词作为value，放入map
        }
        vector<vector<string>> res; //取出所有value
        for(auto it=map.begin(); it!=map.end();++it){ //遍历map
            res.push_back(it->second); //取出所有value
        }
        return res; //返回结果
    }
};