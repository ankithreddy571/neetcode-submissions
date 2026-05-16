class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = {}

        for s in strs:
            arr = [0]*26
            for letter in s:
                arr[ord(letter) - ord('a')] += 1
            word = tuple(arr)
            if word not in res:
                res[word] = []
            res[word].append(s)
        return list(res.values())
        
        