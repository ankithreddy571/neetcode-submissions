class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>> maxHeap;
        int x1 = 0,y1 = 0;
        for(vector<int> point : points){
            int x2 = point[0];
            int y2 = point[1];
            double distance = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
            if(maxHeap.size() < k){
                maxHeap.push({distance,point});
            }else if(maxHeap.top().first > distance){
                maxHeap.push({distance,point});
                maxHeap.pop();
            }
        }
        vector<vector<int>> ans;
        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};
