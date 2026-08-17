class Solution {
public:
    void solve(int col, vector<string> &board, int &cnt,vector<int> &lr, vector<int> &ud, vector<int> &ld, int n){
        if(col == n){
            cnt++;
            return;
        }

        for(int row = 0; row < n; row++){
            if(lr[row] == 0 && ld[row+col] == 0 && ud[n-1+col-row] == 0){
                board[row][col] = 'Q';
                lr[row] = 1;
                ld[row+col] = 1;
                ud[n-1+col-row] = 1;
                solve(col+1,board,cnt,lr,ud,ld,n);
                board[row][col] = '.';
                lr[row] = 0;
                ld[row+col] = 0;
                ud[n-1+col-row] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        int cnt = 0;
        vector<string> board(n);
        string s(n,'.');
        for(int i = 0; i < n; i++){
            board[i] = s;
        }
        vector<int> lr(n,0),ud(2*n-1,0),ld(2*n-1,0);
        solve(0,board,cnt,lr,ud,ld,n);

        return cnt;
    }
};