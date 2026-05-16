class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = defaultdict(list)

        for s in strs:
            arr = [0]*26
            for letter in s:
                arr[ord(letter) - ord('a')] += 1
            res[tuple(arr)].append(s)
        return list(res.values())
        
        