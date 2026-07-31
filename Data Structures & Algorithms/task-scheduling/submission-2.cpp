class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> arr(26,0);
        for(char ch : tasks){
            arr[ch-'A']++;
        }
        priority_queue<int,vector<int>> maxHeap;
        for(int cnt : arr){
            if(cnt > 0){
                maxHeap.push(cnt);
            }
        }
        int t = 0;
        queue<pair<int,int>> q;
        while(!maxHeap.empty() || !q.empty()){
            t++;
            if(maxHeap.empty()){
                t = q.front().second;
            }else{
                int num = maxHeap.top()-1;
                maxHeap.pop();
                if(num > 0){
                    q.push({num,t+n});
                }
            }
            if(!q.empty() && t == q.front().second){
                int k = q.front().first;
                q.pop();
                maxHeap.push(k);
            }
        }
        return t;
    }
};
