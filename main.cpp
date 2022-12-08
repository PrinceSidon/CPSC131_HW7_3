class Solution {
  public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int m = grid.size(), n = m ? grid[0].size() : 0, area = 0, offsets[] = {0, 1, 0, -1, 0};  
      
      for (int i = 0; i < m; i++) {                                            // Loops through every cell
        for (int j = 0; j < n; j++) {
          if (grid[i][j]) {                                                    // Checks that the cell has a 1 in it
            int a = 1;
            grid[i][j] = 0;
            queue<pair<int, int>> todo;                                        // Queue todo stores the unvisited cells
            todo.push({i, j});
            
            while (!todo.empty()) {                                            // BFS ends when todo is empty
              pair<int, int> p = todo.front();
              todo.pop();
              for (int k = 0; k < 4; k++) {                                    // Searches four times for the four directions
                int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c]) {        // Checks if there is an adjacent cell in 
                                                                               // that direction, and if it has a 1
                  grid[r][c] = 0;
                  a++;
                  todo.push({r, c});                                           // Pushes the adjacent cell to todo
                }
              }
            }
            
            area = max(area, a);                                               // Area is at least 1
          }
        }
      }
      
      return area;
    }
};