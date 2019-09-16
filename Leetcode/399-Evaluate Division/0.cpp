class Solution {
private:
    unordered_map<string, vector<pair<string, double>> > graph;
    unordered_map<string, int> visited;
    unordered_map<string, int> valid_values;
    
public:    
    
    double dfs(string curr, string end, double accumulator){
        if (visited[curr]) return -1;
        if (curr == end) return accumulator;
        
        visited[curr] = 1;
        for (auto neigh : graph[curr]){
            double ret = dfs(neigh.first, end, accumulator * neigh.second);
            if (ret > 0)
                return ret;
        }
        visited[curr] = 0;
        return -1;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        for (int i = 0 ; i < equations.size(); ++i){
            auto equation = equations[i];
            double value = values[i];
            valid_values[equation[0]] = 1;
            valid_values[equation[1]] = 1;
            
            graph[equation[0]].push_back({equation[1], value});
            graph[equation[1]].push_back({equation[0], 1 / value});
        }
        
        vector<double> result;
        for (auto querie : queries){
            visited = unordered_map<string, int>();
            if (valid_values[querie[0]] && valid_values[querie[0]])
                result.push_back(dfs(querie[0], querie[1], 1));
            else
                result.push_back(-1);
        }
        
        return result;
    }
};