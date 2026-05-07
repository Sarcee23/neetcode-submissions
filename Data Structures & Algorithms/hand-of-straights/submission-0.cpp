class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) {
            return false;
        }

        unordered_map<int, int> count;
        for(int n : hand) {
            count[n]++;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto& pair : count) {
            minHeap.push(pair.first);
        }

        while(!minHeap.empty()) {
            int first = minHeap.top();
            for(int i = first; i < first + groupSize; i++) {
                if(count.find(i) == count.end() || count[i] == 0) {
                    return false;
                }
                count[i]--;
                if(count[i] == 0) {
                    if(i != minHeap.top()) {
                        return false;
                    }
                    minHeap.pop();
                }
            }
        }
        return true;
    }
};

