class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size();j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        if(fresh == 0) return 0;

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        //to move l,r,up,down
        int t = -1;
        while(!q.empty()){
            t++;
            int n = q.size();
            for(int i = 0; i <n; i++){
                pair<int,int> cell = q.front(); q.pop();

                for(auto dir: directions){
                    int x = cell.first + dir.first;
                    int y = cell.second + dir.second;

                    if( (x >=0 && x <grid.size()) && (y >=0 && y<grid[x].size()) && 
                        grid[x][y] == 1){
                            grid[x][y] = 2;
                            q.push({x,y});
                            fresh--;
                        }
                }

            }
        }
        if(fresh == 0) return t;
        return -1;
    }
};