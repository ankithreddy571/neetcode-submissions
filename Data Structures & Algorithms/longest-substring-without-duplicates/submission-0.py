class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        st = set()
        l,r = 0,0
        size = 0
        for r in range(len(s)):
            
            while s[r] in st:
                st.remove(s[l])
                l+=1
            st.add(s[r])
            size = max(size,r-l+1)
        return size
        