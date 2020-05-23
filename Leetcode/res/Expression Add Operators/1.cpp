\*
Author: allannozomu
Runtime: 340 ms
Memory: 17.3 MB*\

class Solution {
public:
    pair<long, long> operate(long acc, char operation, long num, long previous){
        if (operation == '+') {
            return {acc + num, num};
        } else if (operation == '-'){
            return {acc - num, -num};
        }
        acc -= previous;
        return {acc + previous * num, previous * num};
    }
    
    void operateStr(string& expression, char operation, int num){
        expression.push_back(operation);
        expression += to_string(num);
    }
    
    void deoperateStr(string& expression, char operation, int num){
        expression.pop_back();
        expression.pop_back();
        num /= 10;
        while(num){
            expression.pop_back();
            num /= 10;
        }
    }
    
    void addOperatorsAux(int level, string num, long acc, long previous, long curr, char operation, int target, string& expression, vector<string>& res){
        if (level == num.size()){
            auto new_acc = operate(acc, operation, curr, previous);
            operateStr(expression, operation, curr);
            if (new_acc.first == target){
                res.push_back(expression);
            }
            deoperateStr(expression, operation, curr);
            return;
        }
        int digit = num[level] - '0';

        if (curr){
            addOperatorsAux(level + 1, num, acc, previous, curr * 10 + digit, operation, target, expression, res);
        }
        
        pair<long, long> acc_previous = operate(acc, operation, curr, previous);
        operateStr(expression, operation, curr);
        
        addOperatorsAux(level + 1, num, acc_previous.first, acc_previous.second, digit, '*', target, expression, res);
        addOperatorsAux(level + 1, num, acc_previous.first, acc_previous.second, digit, '+', target, expression, res);
        addOperatorsAux(level + 1, num, acc_previous.first, acc_previous.second, digit, '-', target, expression, res);
        deoperateStr(expression, operation, curr);
    }
    
    vector<string> addOperators(string num, int target) {
        if (num == "") return {};
        
        vector<string> res;
        
        for (int i = 0; i < num.size() - 1; ++i){
            string start_string = num.substr(0, i+1);
            
            addOperatorsAux(i + 2, num, stol(num.substr(0, i+1)), stol(num.substr(0, i+1)), num[i + 1] - '0', '*', target, start_string, res);
            addOperatorsAux(i + 2, num, stol(num.substr(0, i+1)), 0, num[i + 1] - '0', '+', target, start_string, res);
            addOperatorsAux(i + 2, num, stol(num.substr(0, i+1)), 0, num[i + 1] - '0', '-', target, start_string, res);
            if (num[1] && num[0] == '0') return res;
        }
        if (stol(num) == target){
            res.push_back(num);
        }
        // addOperatorsAux(1, num, 0, num[0] - '0', '*', target, "", res);

        return res;
    }
};
