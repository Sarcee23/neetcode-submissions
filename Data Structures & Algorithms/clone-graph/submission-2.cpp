class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        unordered_map<Node*, Node*> oldToNew;
        return dfs(node, oldToNew);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& oldToNew) {
        if (oldToNew.count(node)) {
            return oldToNew[node];
        }

        // Create a copy of the current node
        Node* copy = new Node(node->val);
        oldToNew[node] = copy;

        // Recursively clone all neighbors
        for (Node* nbr : node->neighbors) {
            copy->neighbors.push_back(dfs(nbr, oldToNew));
        }

        return copy;
    }
};

