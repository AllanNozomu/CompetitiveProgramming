class Solution {
public:
    
    
    bool validWordAbbreviation(string word, string abbr) {
        int abbr_val = 0;
        int iw, ia;
        
        for (iw = 0, ia = 0; iw < word.size() && ia < abbr.size(); ++ia){
            char ca = abbr[ia];
            
            if (isdigit(ca)){
                if (abbr_val == 0 && ca == '0') return false;
                abbr_val *= 10;
                abbr_val += ca - '0';
            } else {
                if (abbr_val){
                    iw += abbr_val;
                    abbr_val = 0;
                }
                if (ca == word[iw]){
                    iw++;
                } else {
                    return false;
                }
            }
        }
        if (abbr_val){
            iw += abbr_val;
            abbr_val = 0;
        }
        
        if (iw == word.size() && ia == abbr.size()) return true;
        return false;
    }
};