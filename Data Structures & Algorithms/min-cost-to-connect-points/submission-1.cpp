#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // Prim's algorithm
        int n = points.size();
        unordered_map<int, vector<pair<int, int>>> adj;

        // Build the graph using Manhattan distances
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int cost = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({cost, j});
                adj[j].push_back({cost, i});
            }
        }

        // Prim's algorithm setup
        int res = 0;
        unordered_set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // Start from the first point
        minHeap.push({0, 0}); // {cost, index}
        
        while (visited.size() < n) {
            auto curr = minHeap.top();
            minHeap.pop();
            int cost = curr.first;
            int index = curr.second;

            if (visited.count(index)) {
                continue;
            }
            res += cost;
            visited.insert(index);

            for (const auto& nbr : adj[index]) {
                int neiCost = nbr.first;
                int neiIndex = nbr.second;
                if (!visited.count(neiIndex)) {
                    minHeap.push({neiCost, neiIndex});
                }
            }
        }

        return res;
    }
};
