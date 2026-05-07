class Solution:
    dirs = [[1,0],[-1,0],[0,1],[0,-1]]
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        
        rows = len(grid)
        cols = len(grid[0])
        for r in range (rows):
            for c in range (cols):
                if grid[r][c] == 1:
                    return self.dfs(grid,r,c)
        return 0
    
    def dfs(self,grid,r,c):
        
        rows = len(grid)
        cols = len(grid[0])

        if(r<0 or r>=rows or c<0 or c>=cols):
            return 1
        
        if grid[r][c] == 0 :
            return 1
        if grid[r][c] == -1:
            return 0
        grid[r][c] = -1
        
        perimeter = 0
        for dr,dc in self.dirs:
            perimeter+=self.dfs(grid,r+dr,c+dc)
        
        return perimeter

