class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        //make adjacency list
        for(auto prereq : prerequisites){
            int a = prereq[0];
            int b = prereq[1];
            indegree[a]++;
            adj[b].push_back(a);
        }
        int completed =  0 ;
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int course= q.front();
            q.pop();
            completed++;
            for(auto next: adj[course]){
                indegree[next]--;
                if(indegree[next] == 0){
                    q.push(next);
                }
            }
        }
        return completed == numCourses;
    }
};
