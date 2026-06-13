class Solution {
public:
    int find(int n, vector<int> &parent) {
        if(n == parent[n]) return n;
        return parent[n] = find(parent[n], parent);
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int components = n;
        vector<int> parent(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        vector<int> rank(n, 1);
        for(int i = 0; i < edges.size(); i++) {
            int p1 = find(edges[i][0], parent);
            int p2 = find(edges[i][1], parent);
            if(p1 == p2) continue;
            components--;
            if(rank[p1] > rank[p2]) {
                parent[p2] = p1;
            } else if(rank[p2] > rank[p1]){
                parent[p1] = p2;
            } else {
                parent[p2] = p1;
                rank[p1]++;
            }
        }
        return components;
    }
};
