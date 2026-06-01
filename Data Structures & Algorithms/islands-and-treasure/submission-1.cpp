class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> cells;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0) {
                    cells.push({i, j});
                }
            }
        }
        int dist = 0;
        while(!cells.empty()) {
            int lim = cells.size();
            for(int k = 0; k < lim; k++) {
                int x = cells.front().first, y = cells.front().second;
                cells.pop();
                if (grid[x][y] < dist) continue;
                grid[x][y] = dist;
                for(int i = 0; i < 4; i++) {
                    int p = x + dirs[i].first;
                    int q = y + dirs[i].second;
                    if(p < 0 || q < 0 || p >= grid.size() || q >= grid[0].size() || grid[p][q] <= dist + 1) continue;
                    cells.push({p, q});
                }
            }
            dist++;
        }
    }
};

