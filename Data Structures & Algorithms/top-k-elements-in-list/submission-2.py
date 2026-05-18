class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mp = {}
        for num in nums:
            mp[num] = mp.get(num,0)+1
        
        arr = []
        for s,v in mp.items():
            arr.append([v,s])
        
        arr.sort()

        res = []
        
        while len(res) < k:
            res.append(arr.pop()[1])
      
        return res


        