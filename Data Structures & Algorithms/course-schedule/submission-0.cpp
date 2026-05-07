class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> preMap(numCourses);
        for (auto& pair : prerequisites) {
            preMap[pair[0]].push_back(pair[1]);
        }

        vector<bool> visiting(numCourses, false);
        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c, preMap, visiting)) {
                return false;
            }
        }
        return true;
    }

private:
    bool dfs(int crs, vector<vector<int>>& preMap, vector<bool>& visiting) {
        if (visiting[crs]) {
            return false;
        }
        if (preMap[crs].empty()) {
            return true;
        }

        visiting[crs] = true;
        for (int pre : preMap[crs]) {
            if (!dfs(pre, preMap, visiting)) {
                return false;
            }
        }
        visiting[crs] = false;
        preMap[crs].clear();
        return true;
    }
};
