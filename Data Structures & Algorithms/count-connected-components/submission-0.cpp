class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // Initialize the parent and rank vectors
        vector<int> par(n);
        vector<int> rank(n, 1);
        for (int i = 0; i < n; ++i) {
            par[i] = i;  // Each node is its own parent initially
        }
        
        int result = n;
        for (const auto& edge : edges) {
            int n1 = edge[0];
            int n2 = edge[1];
            // If Union is successful, decrease the component count
            if (Union(par, rank, n1, n2)) {
                --result;
            }
        }
        return result;
    }

private:
    int Find(vector<int>& par, int n) {
        int p = par[n];
        while (p != par[p]) {
            par[p] = par[par[p]];  // Path compression
            p = par[p];
        }
        return p;
    }

    bool Union(vector<int>& par, vector<int>& rank, int n1, int n2) {
        int p1 = Find(par, n1);
        int p2 = Find(par, n2);
        if (p1 == p2) {
            return false;  // Already in the same component
        }
        
        // Union by rank
        if (rank[p1] > rank[p2]) {
            par[p2] = p1;
            rank[p1]+=rank[p2];
        } else if (rank[p1] < rank[p2]) {
            par[p1] = p2;
            rank[p2]+=rank[p1];
        } else {
            par[p2] = p1;
            rank[p1]+= rank[p2];
        }
        return true;
    }
};

