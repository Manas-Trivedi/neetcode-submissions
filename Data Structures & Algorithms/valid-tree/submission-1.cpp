class Solution {
public:
    bool dfs(int curr, int parent, unordered_map<int, vector<int>> &graph, vector<bool> &visited) {
        visited[curr] = true;
        for(int neighbor: graph[curr]) {
            if(visited[neighbor] == true && parent != neighbor) return false;
            if(neighbor != parent && !dfs(neighbor, curr, graph, visited)) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph(n);
        for(int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n + 1, false);
        if(!dfs(0, n, graph, visited)) return false;
        for(int i = 0; i < n; i++) if(!visited[i]) return false;
        return true;
    }
};
