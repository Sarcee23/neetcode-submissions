class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        i = -1
        ans = 0

        while i >= -len(s) and s[i] == ' ':
            i -= 1

        while i >= -len(s) and s[i] != ' ':
            ans += 1
            i -= 1

        return ans
