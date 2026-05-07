class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        //store arrival with dest and cost
        unordered_map<int,vector<pair<int,int>>> edges;
        for (const auto&  time: times){
            edges[time[0]].emplace_back(time[1],time[2]);
        }

        //make a minHeap to have least cost at top
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> minHeap;
        minHeap.push({0,k}); // cost of entering k node is 0
        
        set<int>visited;// to track visited nodes.
        int t = 0; // var that stores the time

        while(!minHeap.empty()){
            //get the min cost deets
            auto curr = minHeap.top();
            minHeap.pop();
            int cost= curr.first;
            int dest = curr.second;
            //if already visited the dest then skip
            if(visited.count(dest)){
                continue;
            }
            //if not then mark visited and add its cost
            visited.insert(dest);
            t = cost;

            //check its neighbors
            if(edges.count(dest)){
                for(const auto& next: edges[dest]){
                    int nextDest = next.first;
                    int nextCost  = next.second;
                    //if not visited its neighbor add it to minHeap and increment the cost
                    if(!visited.count(nextDest)){
                        minHeap.push({nextCost+cost,nextDest});
                    }
                }
            }
        }
        return visited.size() == n ? t : -1;
    }
};
