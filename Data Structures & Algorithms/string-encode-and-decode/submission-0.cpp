class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (const string& s : strs) {
            res += to_string(s.size()) + "|" + s;
        }
        return res;
    }

    vector<string> decode(string str) {
        vector<string> res;
        int i = 0;
        while (i < str.size()) {
            int j = i;
            while (str[j] != '|') {
                j++;
            }
            int size = stoi(str.substr(i, j - i));
            string word = str.substr(j + 1, size);
            res.push_back(word);
            i = j + 1 + size;
        }
        return res;
    }
};
