class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans(temperatures.size(),0);
        stack<pair<int,int>>stk; //value,index
        for(int i = 0; i<temperatures.size();i++){
            int curVal = temperatures[i];
            while(!stk.empty() && curVal>stk.top().first){
                auto pair = stk.top();
                stk.pop();
                ans[pair.second] = i - pair.second;
            }
            stk.push({curVal,i});
        }
        return ans;
    }
};
