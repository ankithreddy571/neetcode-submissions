using namespace std;
class KthLargest {
    
public:
    priority_queue<int,vector<int>,greater<>> minheap;
    int k;
    KthLargest(int k, vector<int>& nums):k(k) {
        for(int num : nums){
            add(num);
        }
    }
    
    int add(int val) {
        if(minheap.size() < k){
            minheap.push(val);
        }else{
            if(minheap.top() < val){
                minheap.pop();
                minheap.push(val);
            }
        }
        return minheap.top();
    }
};