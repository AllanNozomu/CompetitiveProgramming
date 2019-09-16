class MinStack {
public:
    /** initialize your data structure here. */
    
    stack<int> min_stack;
    stack<int> normal_stack;
    
    MinStack() {
        
    }
    
    void push(int x) {
        if (normal_stack.empty() || min_stack.top() >= x){
            min_stack.push(x);
        }
        normal_stack.push(x);
    }
    
    void pop() {
        if (min_stack.top() == normal_stack.top()){
            min_stack.pop();
        }
        normal_stack.pop();
    }
    
    int top() {
        return normal_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */