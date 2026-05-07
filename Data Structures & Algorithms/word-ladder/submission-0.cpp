class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord.length() != endWord.length() || beginWord.empty()) {
            return 0; 
        }
        
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end()) {
            return 0;
        }

        queue<string> q;
        unordered_set<string> visited;
        
        q.push(beginWord);
        visited.insert(beginWord);
        int res = 0;

        while (!q.empty()) {
            res++;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                string currWord = q.front();
                q.pop();
                
                if (currWord == endWord) {
                    return res;
                }
                
                for (int j = 0; j < currWord.size(); ++j) {
                    char originalChar = currWord[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == originalChar) continue; // Skip if no change
                        currWord[j] = c;
                        if (words.find(currWord) != words.end() && visited.find(currWord) == visited.end()) {
                            q.push(currWord);
                            visited.insert(currWord);
                        }
                    }
                    currWord[j] = originalChar; // Restore the original character
                }
            }
        }
        return 0;
    }
};

