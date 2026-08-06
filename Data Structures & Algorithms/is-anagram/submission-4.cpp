class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> arr(26,0);
        for(char ch : s){
            int index = ch - 'a';
            arr[index]++;
        }
        for(char ch : t){
            int index = ch - 'a';
            arr[index]--;
        }
        for(int num : arr){
            if(num != 0){
                return false;
            }
        }
        return true;
    }
};
