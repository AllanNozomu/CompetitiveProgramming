class RandomizedSet {
private:
    unordered_map<int, int> map;
    vector<int> values;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        map = unordered_map<int, int>();
        values = vector<int>();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (map[val]) 
            return false;
        
        map[val] = values.size() + 1;
        values.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!map[val])
            return false;
        
        int pos = map[val] - 1;
        int last = values[values.size() - 1];
        
        map[last] = map[val];
        values[pos] = last;
        values.pop_back();
        
        map[val] = 0;
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return values[rand() % values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */