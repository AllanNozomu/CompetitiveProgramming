class Solution {
public:
    typedef struct Node{
        struct Node* children[26];
        bool terminal;
    } Node;
    
    bool find(Node* root, string& str, int level){
        if (level == str.size()) {
            return root->terminal;
        }
        if (root->children[str[level] - 'a'] != NULL)
            return find(root->children[str[level] - 'a'], str, level + 1);
        
        return false;
    }
    
    void buildTrie(Node* root, string& str, int level){
        if (level == str.size()){
            root->terminal = true;
            return;
        }
        
        if (root->children[str[level] - 'a'] == NULL){
            root->children[str[level] - 'a'] = new Node();
        }
        buildTrie(root->children[str[level] - 'a'], str, level + 1);
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0) return true;
        
        Node* trie = new Node();
        for (string word : wordDict){
            buildTrie(trie, word, 0);
        }
        
        int dp[s.size() + 1] = {0};

        dp[0] = 1;
        for (int i = 0; i < s.size(); ++i){
            for (int j = 1; i + j <= s.size(); ++j) {
                string str = s.substr(i, j);
                if (find(trie, str, 0)){
                    dp[i + j] |= dp[i];
                }
            }
        }
        return dp[s.size()];
    }
};