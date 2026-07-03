class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> temp(n,vector<int>(n,0));
        vector<int> delr = {-1,1,0,0};
        vector<int> delc = {0,0,1,-1};
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int sum = 0;
                for(int k = 0; k < 4; k++){
                    int nr = i+delr[k];
                    int nc = j+delc[k];
                    if(nr<0 || nc < 0 || nr >= n || nc >= n){
                        continue;
                    }
                    sum += min(grid[i][j], grid[nr][nc]);
                }
                // if(4*grid[i][j] >= sum){
                    temp[i][j] = 4*grid[i][j] - sum;
                // }
                if(grid[i][j] != 0){
                    temp[i][j]+=2;
                }
                res+=temp[i][j];
            }   
        }
    return res;
    }
};