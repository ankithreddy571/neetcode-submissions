class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxheap;
        for(int stone : stones){
            maxheap.push(stone);
        }
        while(maxheap.size() > 1){
            int y = maxheap.top();
            maxheap.pop();
            int x = maxheap.top();
            maxheap.pop();
            if(y!=x){
                maxheap.push(y-x);
            }
        }
        return maxheap.size() ? maxheap.top() : 0;
    }
};
