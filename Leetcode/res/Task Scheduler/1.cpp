\*
Author: allannozomu
Runtime: 48 ms
Memory: 9.5 MB*\

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int count[26] = {};
        int chunks_number = 0;
        int chunks_index_numbers = 0;
        
        for (char c : tasks){
            count[c -'A']++;
            if (chunks_number < count[c -'A']) {
                chunks_number = count[c -'A'];
                chunks_index_numbers = 1;
            } else if (chunks_number == count[c -'A']){
                chunks_index_numbers++;
            }
        }
        int tasks_inside_chunks = tasks.size() - chunks_number * chunks_index_numbers;
        int idle_time = max(0, (chunks_number - 1) * (n - chunks_index_numbers + 1) - tasks_inside_chunks);
        return tasks.size() + idle_time;
    }
};