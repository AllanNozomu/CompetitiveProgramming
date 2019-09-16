class Solution {
static double distance(pair<int, int> p){
    return sqrt(p.first*p.first + p.second*p.second);
}

static int comp(pair<int, int> a, pair<int, int> b){
    return distance(a) < distance(b);
}
    
public:
    
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<int, int>> pair_points;
        
        for (auto point : points){
            pair_points.push_back({point[0], point[1]});
        }
        sort(pair_points.begin(), pair_points.end(), comp);
        
        vector<vector<int>> res_points;
        for (int i = 0; i < K; ++i){
            res_points.push_back({pair_points[i].first, pair_points[i].second});
        }
        return res_points;
    }
};