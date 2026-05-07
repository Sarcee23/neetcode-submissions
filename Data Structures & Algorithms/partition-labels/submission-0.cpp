class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>lastIndex;
        vector<int>res;
        for(int j=0;j<s.length();j++){
            char c = s[j];
            lastIndex[c] = j;
        }   
        int curLen =  0;    
        int goal = 0;
        int i=0;
        for(int i =0; i<s.length();i++){
             char c = s[i];
            goal = max(goal,lastIndex[c]);
            curLen++;
            if(goal == i){
                res.push_back(curLen);
                curLen=0;
            }
        }
        return res;


    }
};
