class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charMap(256, -1); // track last seen index of each char
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            if (charMap[s[right]] != -1) {
                left = max(left, charMap[s[right]] + 1);
            }
            charMap[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

