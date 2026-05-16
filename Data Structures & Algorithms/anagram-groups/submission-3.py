class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = {}
        for s in strs:
            arr = [0]*26
            for c in s:
                arr[ord(c) - ord('a')] += 1
            k = tuple(arr)
            if k not in res:
                res[k] = []
            res[k].append(s)
        return list(res.values())
        
        