from collections import deque
class Solution:
    def maxDepth(self, s: str) -> int:
        stack = deque()
        ans = 0
        curSize =0 
        for char in s:
            if char == '(':
                stack.append(char)
                curSize+=1
                ans = max(ans,curSize)
            elif (char ==')' and len(stack)!=0):
                    stack.pop()
                    curSize -=1
        return ans