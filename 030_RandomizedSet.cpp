//
// Created by 23116 on 2023/05/12.
//
class RandomizedSet {
public:
    unordered_map<int, int> numToLoc;
    vector<int> nums;
    /** Initialize your data structure here. */
    RandomizedSet() {
        numToLoc.clear();
        nums.clear();
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(numToLoc.find(val)!=numToLoc.end()){
            return false;
        }
        nums.push_back(val);
        numToLoc[val]=nums.size()-1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(numToLoc.find(val)==numToLoc.end()){
            return false;
        }
        int loc=numToLoc[val];
        nums[loc]=nums[nums.size()-1];
        numToLoc[nums[nums.size()-1]]=loc;
        nums.pop_back();
        numToLoc.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */