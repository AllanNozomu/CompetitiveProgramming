\*
Author: allannozomu
Runtime: 24 ms
Memory: 12.7 MB*\

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> word_counter;
        set<pair<int, string>> res;
        
        for(string &word : words){
            int count = word_counter[word];
            word_counter[word]--;
            
            set<pair<int, string>>::iterator element = res.find({count, word});
            if (element != res.end()){
                res.erase(element);
                res.insert({count - 1, word});
            } else {
                if (res.size() < k) {
                    res.insert({count - 1, word});
                } else {
                    auto last_element = res.rbegin();
                    if (last_element->first > (count - 1) ||
                            (last_element->first == count - 1 && last_element->second > word)){
                        res.erase(*last_element);
                        res.insert({count - 1, word});
                    }
                }
            }
        }
        vector<string> vector_res = vector<string>();
        for (auto element = res.begin(); element != res.end(); ++element){
            vector_res.push_back(element->second);
        }
        return vector_res;
    }
};