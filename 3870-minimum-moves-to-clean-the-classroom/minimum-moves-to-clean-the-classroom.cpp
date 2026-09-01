class Solution {
public:
    int minMoves(vector<string>& cr, int energy) {
        int n = cr.size();
        int m = cr[0].size();

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        int sx = -1, sy = -1;
        int cnt = 0;

        vector<vector<int>> id(n, vector<int>(m, -1));

        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {

                if(cr[r][c] == 'S') {
                    sx = r;
                    sy = c;
                }

                if(cr[r][c] == 'L') {
                    id[r][c] = cnt++;
                }
            }
        }

        int masks = 1 << cnt;

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> vis(
            n,
            vector<vector<vector<bool>>>(
                m,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(masks, false)
                )
            )
        );

        // row, col, energy, mask
        queue<array<int,4>> q;

        q.push({sx, sy, energy, 0});
        vis[sx][sy][energy][0] = true;

        int moves = 0;

        while(!q.empty()) {

            int sz = q.size();

            while(sz--) {

                auto [r, c, e, mask] = q.front();
                q.pop();

                if(mask == (1 << cnt) - 1)
                    return moves;

                if(e == 0)
                    continue;

                for(int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr < 0 || nc < 0 ||
                       nr >= n || nc >= m)
                        continue;

                    if(cr[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    // Collect litter
                    if(cr[nr][nc] == 'L') {
                        nmask |= (1 << id[nr][nc]);
                    }

                    // Recharge
                    if(cr[nr][nc] == 'R') {
                        ne = energy;
                    }

                    if(!vis[nr][nc][ne][nmask]) {

                        vis[nr][nc][ne][nmask] = true;

                        q.push({
                            nr,
                            nc,
                            ne,
                            nmask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};