class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pair;
        for(int i=0;i<position.size();i++){
            pair.push_back({position[i],speed[i]});
        }

        sort(pair.rbegin(),pair.rend());
        vector<double>hybridStack;
        for(auto& p : pair){
            hybridStack.push_back((double)(target- p.first)/p.second);
            double curTime = hybridStack.back();
        double prevTime = hybridStack[hybridStack.size() - 2];
            if(hybridStack.size() >= 2 && curTime<=prevTime ){
                hybridStack.pop_back();
            }
        }
        return hybridStack.size();
    }
};
