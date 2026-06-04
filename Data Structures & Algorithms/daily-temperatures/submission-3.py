class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        res = [0]*len(temperatures)
        stack = []

        for index,val in enumerate(temperatures):
            while stack and val > stack[-1][0]:
                last_val,last_index = stack.pop()
                res[last_index] = index-last_index
            stack.append((val,index))
        return res

        