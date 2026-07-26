class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>> maxheap;
        for(int stone : stones){
            maxheap.push(stone);
        }
        while(maxheap.size() > 1){
            int b = maxheap.top();
            maxheap.pop();
            int a = maxheap.top();
            maxheap.pop();
            if(b > a){
                maxheap.push(b-a);
            }
        }
        return maxheap.size() ? maxheap.top() : 0;
    }
};
