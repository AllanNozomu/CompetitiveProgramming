\*
Author: allannozomu
Runtime: 80 ms
Memory: 67.5 MB*\

class Trie {
private:
    typedef struct Node {
        vector<Node*> nodes = vector<Node*>(26);
        bool terminal = false;
    } Node;
    
    void buildNode(string& word, int index, Node* root){
        if (index == word.size()) {
            root->terminal = true;
            return;
        }
        int c = word[index] - 'a';
        if (root->nodes[c] == NULL){
            root->nodes[c] = new Node();
        }
        buildNode(word, index + 1, root->nodes[c]);
    }
    
    int search(string word, int index, Node* root, bool complete){
        if (root == NULL) return 0;
        if (index == word.size()) {
            return !complete || root->terminal == complete;
        }
        int c = word[index] - 'a';
        return search(word, index + 1, root->nodes[c], complete);
    }
    
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        buildNode(word, 0, root);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return search(word, 0, root, true);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return search(prefix, 0, root, false);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */