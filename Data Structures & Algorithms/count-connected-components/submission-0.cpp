class Solution {
public:
    void dfs(int curr, vector<vector<int>> &graph, vector<bool> &vst) {
        vst[curr] = true;
        for(int node: graph[curr]) {
            if(!vst[node]) dfs(node, graph, vst);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int components = 0;
        vector<vector<int>> graph(n);
        for(vector<int> v: edges) {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                components++;
                dfs(i, graph, visited);
            }
        }
        return components;
    }
};
