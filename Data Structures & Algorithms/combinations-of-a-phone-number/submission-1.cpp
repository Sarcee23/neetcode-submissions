class Solution {
    private:
    vector<string>res;
    vector<string> digToChar = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    vector<string> letterCombinations(string digits) {  
        if(digits.empty()){
            return res;
        }
        backtrack(0,"",digits);
        return res;
    }
    void backtrack(int i, string curStr, string digits){
       
        if(curStr.size() == digits.size()){
            res.push_back(curStr);
            return;
        }
      string chars = digToChar[digits[i] -'0'];
      for(char c: chars){
        backtrack(i+1,curStr+c,digits);
      }
    }
};
