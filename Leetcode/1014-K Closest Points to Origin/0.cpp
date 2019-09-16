class Solution {
    
static double distance(vector<int> p){
    return sqrt(p[0]*p[0] + p[1]*p[1]);
}

static int comp(vector<int> a, vector<int> b){
    return distance(a) < distance(b);
}
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        multiset<vector<int>, decltype(&comp)> pair_points(&comp);
        int i;
        
        for (i = 0; i < K; ++i){
            pair_points.insert(points[i]);
        }
        
        for (; i < points.size(); ++i){
            vector<int> curr = points[i];
            if (comp(curr, *pair_points.rbegin())){
                pair_points.erase(--pair_points.end());
                pair_points.insert(curr);
            }
        }
        
        return vector<vector<int>>(pair_points.begin(), pair_points.end());
    }
};