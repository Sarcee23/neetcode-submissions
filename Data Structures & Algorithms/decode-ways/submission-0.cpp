class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;

        int temp1 = 1;
        int temp2 = (s[0] - '0') == 0 ? 0 : 1;

        for (int i = 2; i <= n; i++) {
            int oneDigit = stoi(s.substr(i - 1, 1));
            int twoDigit = stoi(s.substr(i - 2, 2));
            int res = 0;

            if (oneDigit >= 1) {
                res += temp2;
            }
            if (twoDigit >= 10 && twoDigit <= 26) {
                res += temp1;
            }

            // Update temp1 and temp2 for the next iteration
            temp1 = temp2;
            temp2 = res;
        }

        return temp2;
    }
};
