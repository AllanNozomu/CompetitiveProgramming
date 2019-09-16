class Solution {
public:
    int find(int pos, vector<int>& positions){
        if (positions[pos] != pos){
            positions[pos] = find(positions[pos], positions);
        }
        return positions[pos];
    }
    
    void _union(int x, int y, vector<int>& positions){
        positions[find(y, positions)] = positions[find(x, positions)];
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> email_name;
        unordered_map<string, int> email_id;
        
        vector<int> positions;
        int email_count = 0;
        
        for (auto account : accounts){
            for (int i = 1; i < account.size(); ++i){
                string email = account[i];
                email_name[email] = account[0];
                
                if (email_id.find(email) == email_id.end()){
                    email_id[email] = email_count;
                    positions.push_back(email_count);
                    email_count++;
                }
                
                _union(email_id[account[1]], email_id[email], positions);
            }
        }
        
        unordered_map<int, set<string>> merged_accounts;
        for (auto en : email_name){
            merged_accounts[find(email_id[en.first], positions)].insert(en.first);
        }
        
        vector<vector<string>> res;
        for (auto merged_account : merged_accounts){
            vector<string> new_account;
            new_account.push_back(email_name[*merged_account.second.begin()]);
            new_account.insert(new_account.end(), merged_account.second.begin(), merged_account.second.end());
            res.push_back(new_account);
        }
        
        return res;
    }
};