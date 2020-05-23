\*
Author: allannozomu
Runtime: 172 ms
Memory: 55.4 MB*\

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, unordered_set<string>> graph;
        unordered_map<string, string> emails_to_names;
        
        for (auto &account : accounts){
            if (graph.find(account[1]) == graph.end()){
                graph[account[1]] = {};
            }
            for (int i = 1; i < account.size(); ++i){
                emails_to_names[account[i]] = account[0];
                if (i > 1){
                    if (graph.find(account[i]) == graph.end()){
                        graph[account[i]] = {};
                    }
                    graph[account[1]].insert(account[i]);
                    graph[account[i]].insert(account[1]);
                }
            }
        }
        vector<vector<string>> merged_accounts;
        unordered_set<string> visited;
        
        for (auto& node : graph){
            if (visited.find(node.first) != visited.end()) continue;
            
            vector<string> account_emails;
            queue<string> emails_queue;
            visited.insert(node.first);
            emails_queue.push(node.first);
            
            while(!emails_queue.empty()){
                string curr_email = emails_queue.front();
                emails_queue.pop();
                
                account_emails.push_back(curr_email);
                for (auto neighbour : graph[curr_email]){
                    if (visited.find(neighbour) == visited.end()){
                        visited.insert(neighbour);
                        emails_queue.push(neighbour);
                    }
                }
            }
            sort(account_emails.begin(), account_emails.end());
            vector<string> new_account = {emails_to_names[node.first]};
            new_account.insert(new_account.end(), account_emails.begin(), account_emails.end());
            merged_accounts.push_back(new_account);
        }
        
        return merged_accounts;
    }
};