class Solution {
public:
    bool isValid(string s) {
        stack<char> open_stacks;
        
        for (char c : s){
            if (c == '(' || c == '[' || c == '{')
                open_stacks.push(c);
            else {
                if (open_stacks.size() <= 0){
                    return false;
                }
                char open_char = open_stacks.top();
                open_stacks.pop();
                if (open_char == '(' && c != ')')
                    return false;
                if (open_char == '[' && c != ']')
                    return false;
                if (open_char == '{' && c != '}')
                    return false;
            }
        }
        
        return open_stacks.empty();
    }
};