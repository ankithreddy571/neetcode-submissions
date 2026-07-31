class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> arr(26,0);
        for(char ch : tasks){
            arr[ch-'A']++;
        }
        priority_queue<int,vector<int>> maxHeap;
        for(int num : arr){
            if(num > 0){
                maxHeap.push(num);
            }
        }
        queue<pair<int,int>> q;
        int time = 0;
        while(!maxHeap.empty() || !q.empty()){
            time++;
            if(maxHeap.empty()){
                time = q.front().second;
            }else{
                int num = maxHeap.top()-1;
                maxHeap.pop();
                if(num > 0){
                    q.push({num,time+n});
                }
            }
            if(!q.empty() && q.front().second == time){
                int x = q.front().first;
                q.pop();
                maxHeap.push(x);
            }
        }
        return time;
    }
};
