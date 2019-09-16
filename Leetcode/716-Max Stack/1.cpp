class MaxStack {
private:
    stack<int> values;
    stack<int> max_stack;
public:
    /** initialize your data structure here. */
    MaxStack() {
        stack<int> values = stack<int>();
        stack<int> max_stack = stack<int>();
    }
    
    void push(int x) {
        values.push(x);
        
        if (max_stack.empty()){
            max_stack.push(x);
        } else {
            max_stack.push(max(x, max_stack.top()));
        }
    }
    
    int pop() {
        int value = values.top();
        values.pop();
        max_stack.pop();
        return value;
    }
    
    int top() {
        return values.top();
    }
    
    int peekMax() {
        return max_stack.top();
    }
    
    int popMax() {
        stack<int> aux;
        int max_value = max_stack.top();
        
        while(values.top() != max_stack.top()){
            aux.push(values.top());
            values.pop();
            max_stack.pop();
            max_value = max_stack.top();
        }
        
        values.pop();
        max_stack.pop();
        
        while(!aux.empty()){
            push(aux.top());
            aux.pop();
        }
        return max_value;
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