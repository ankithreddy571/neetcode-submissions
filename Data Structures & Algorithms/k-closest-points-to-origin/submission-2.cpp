class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>,
                    vector<pair<double,int>>,
                    greater<pair<double,int>>> minheap;
        vector<vector<int>> ans;
        int x1 = 0,y1 = 0;
        for(int i = 0;i < points.size();i++){
            int x2 = points[i][0];
            int y2 = points[i][1];
            double distance = sqrt((x1-x2)*(x1-x2)+
                                (y1-y2)*(y1-y2));
            minheap.push({distance,i});
        }
        while(k--){
            int index = minheap.top().second;
            minheap.pop();
            ans.push_back(points[index]);
        }
        return ans;
    }
};
