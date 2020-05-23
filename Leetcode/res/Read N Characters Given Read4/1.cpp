\*
Author: allannozomu
Runtime: 0 ms
Memory: 8.3 MB*\

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int ret = 0;
        
        while(n > 0){
            int char_read = min(read4(buf), n);
            
            buf += char_read;
            ret += char_read;
            n -= char_read;
            
            if (char_read < 4) break;
        }
        
        return ret;
    }
};