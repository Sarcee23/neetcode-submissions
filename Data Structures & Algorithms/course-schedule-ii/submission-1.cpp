class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        vector<int> order;
        
        int completed = 0;
        //create adj list
        for(auto prereq: prerequisites){
            int a = prereq[0];
            int b = prereq[1];
            indegree[a]++;
            adj[b].push_back(a);
        }
        queue<int>q;
        for(int i =0;i<indegree.size();i++){
            if(indegree[i] ==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            order.push_back(curr);
            completed++;
            for(auto next:adj[curr]){
                indegree[next]--;
                if(indegree[next] == 0){
                    q.push(next);
                }
            }
        }
        return numCourses==completed?order:std::vector<int>{};
    }
};
