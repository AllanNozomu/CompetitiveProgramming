\*
Author: allannozomu
Runtime: 16 ms
Memory: 9.8 MB*\

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comp(Interval a, Interval b){
        return a.start < b.start;
}
class Solution {
public:
   
    
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 0)
            return intervals;
        
        sort(intervals.begin(), intervals.end(), comp);
        
        vector<Interval> res;
        Interval previous = intervals[0];
        
        for(Interval interval : intervals){
            if (previous.end >= interval.start){
                previous = Interval(previous.start, max(interval.end, previous.end));
            }else {
                res.push_back(previous);
                previous = interval;
            }
        }
        res.push_back(previous);
        return res;
    }
};