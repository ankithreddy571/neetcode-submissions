class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //unordered_map<double,vector<int>> mp;
        priority_queue<pair<double,int>,
            vector<pair<double,int>>,greater<pair<double,int>>> minheap;
        vector<vector<int>> ans;
        double x1 = 0,y1 = 0;
        for(int i = 0;i < points.size();i++){
            int x2 = points[i][0];
            int y2 = points[i][1];
            double distance = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
            minheap.push({distance,i});
        }
        while(k){
            int i = minheap.top().second;
            ans.push_back(points[i]);
            minheap.pop();
            k--;
        }
        return ans;
    }
};
