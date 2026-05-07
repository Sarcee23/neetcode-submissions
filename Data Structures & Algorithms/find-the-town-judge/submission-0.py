class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        
        indegree  = [0]*(n+1)
        outdegree = [0]*(n+1)
        
        for [frm,to] in trust:
            outdegree[frm] +=1
            indegree[to] +=1
        
        for person in range(n+1):
            if outdegree[person] ==0 and indegree[person] == n-1:
                return person
        return -1
