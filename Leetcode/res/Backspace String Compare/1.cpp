\*
Author: allannozomu
Runtime: 0 ms
Memory: 8.8 MB*\

class Solution {
public:
    stack<char> build_stack(string& s){
        stack<char> char_stack;
        
        for (char c : s){
            if (c == '#'){
                if (!char_stack.empty()) char_stack.pop();
            } else {
                char_stack.push(c);
            }
        }
        
        return char_stack;
    }
    
    bool backspaceCompare(string S, string T) {
        stack<char> stack_s, stack_t;
        
        stack_s = build_stack(S);
        stack_t = build_stack(T);
        
        while (!stack_s.empty() && !stack_t.empty()){
            if (stack_s.top() != stack_t.top()) return false;
            stack_s.pop();
            stack_t.pop();
        }
        
        return stack_s.empty() && stack_t.empty();
    }
};