class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>> maxHeap;
        for(int stone : stones){
            maxHeap.push(stone);
        }
        while(maxHeap.size() > 1){
            int first_stone = maxHeap.top();
            maxHeap.pop();
            int second_stone = maxHeap.top();
            maxHeap.pop();
            if(first_stone > second_stone){
                int new_stone = first_stone-second_stone;
                maxHeap.push(new_stone);
            }
        }
        return (maxHeap.size() == 1) ? maxHeap.top() : 0;
    }
};
