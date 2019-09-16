class Solution {
public:
    vector<char> getCharacters(char c){
        switch(c){
            case '2': return {'a', 'b', 'c'};
            case '3': return {'d', 'e', 'f'};
            case '4': return {'g', 'h', 'i'};
            case '5': return {'j', 'k', 'l'};
            case '6': return {'m', 'n', 'o'};
            case '7': return {'p', 'q', 'r', 's'};
            case '8': return {'t', 'u', 'v'};
            case '9': return {'w', 'x', 'y', 'z'};
        }
        return {};
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        
        vector<string> combinations = {""};
        
        for (char digit : digits){
            vector<string> new_combinations;
            for (auto combination : combinations){
                for (char c : getCharacters(digit)){
                    new_combinations.push_back(combination + c);
                }
            }
            combinations = new_combinations;
        }
        
        return combinations;
    }
};