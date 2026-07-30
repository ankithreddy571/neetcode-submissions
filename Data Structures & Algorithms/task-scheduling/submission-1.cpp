class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char ch : tasks){
            freq[ch-'A']++;
        }

        priority_queue<int> pq;
        for(int cnt : freq){
            if(cnt>0){
                pq.push(cnt);
            }
        }

        queue<pair<int,int>> q;
        int time = 0;
        while(!q.empty() || !pq.empty()){
            time++;

            if(pq.empty()){
                time = q.front().second;
            }else{
                int cnt = pq.top()-1;
                pq.pop();
                if(cnt > 0){
                    q.push({cnt,time+n});
                }
            }

            if(!q.empty() && q.front().second == time){
                int cnt = q.front().first;
                q.pop();
                pq.push(cnt);
            }
        }
        return time;
    }
};
