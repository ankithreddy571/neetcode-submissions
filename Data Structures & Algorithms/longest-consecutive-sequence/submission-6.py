class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        st = set()
        for i in range(len(nums)):
            st.add(nums[i])
        total = 0
        for i in range(len(nums)):
            cur = nums[i]
            size = 0
            if not (nums[i]-1) in st:
                while cur in st:
                    cur = cur+1
                    size += 1
            total = max(total,size)
        return total

        