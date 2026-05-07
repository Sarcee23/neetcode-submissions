class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        //create adj list and indegree array
        for(auto&prereq: prerequisites){
                int a = prereq[0];
                int b = prereq[1];
                indegree[a]++;
                adj[b].push_back(a);
        }
       queue<int>q;
       for(int i=0;i<numCourses;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
       }
       int courses = 0;
       while(!q.empty()){
        courses++;
        int course = q.front();
        q.pop();
        for(int next: adj[course]){
            indegree[next]-- ;
            if(indegree[next] == 0){
                q.push(next);
            }
        }
       }
       return courses == numCourses;
    }
};
