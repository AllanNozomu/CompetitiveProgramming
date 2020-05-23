\*
Author: allannozomu
Runtime: 104 ms
Memory: 33.4 MB*\

class MaxStack {
private:
    map<int, vector<list<int>::iterator>> nodes;
    list<int> values;
public:
    /** initialize your data structure here. */
    MaxStack() {
        values = list<int>();
        nodes = map<int, vector<list<int>::iterator>>();
    }
    
    void push(int x) {
        values.insert(values.begin(), x);
        nodes[x].push_back(values.begin());
    }
    
    int pop() {
        int value = *(values.begin());
        values.erase(values.begin());
        
        nodes[value].pop_back();
        if (nodes[value].empty()){
            nodes.erase(value);
        }
            
        return value;
    }
    
    int top() {
        return *(values.begin());
    }
    
    int peekMax() {
        return nodes.rbegin()->first;
    }
    
    int popMax() {
        int value = peekMax();
        
        list<int>::iterator it = nodes[value].back();
        values.erase(it);
        
        nodes[value].pop_back();
        if (nodes[value].empty()){
            nodes.erase(value);
        }
        
        return value;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */