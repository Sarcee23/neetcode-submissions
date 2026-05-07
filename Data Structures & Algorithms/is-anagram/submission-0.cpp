class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!= t.size()){
            return false;
        }
        unordered_map<char,int>freqMap;
        for(char c : s){
            freqMap[c]++;
        }
        for(char c : t){
            if(freqMap[c] == 0){
                return false;
            }
            freqMap[c]--;
        }
        return true;

    }
};
