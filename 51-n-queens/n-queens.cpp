class Solution {
public:
    // void solve(int t,int i, vector<string> &res,vector<vector<string>> &ress,int n){
    //     // All queens placed
    //     if(t == n) {
    //         vector<string> temp = res;
    //         for(int i = 0; i < n; i++) {
    //             for(int j = 0; j < n; j++) {
    //                 if(temp[i][j] == 'X') {
    //                     temp[i][j] = '.';
    //                 }
    //             }
    //         }
    //         ress.push_back(temp);
    //         return;
    //     }

    //     if(i == n){
    //         return;
    //     }
    //     for(int j = 0; j < n; j++) {
    //         if(res[i][j] == '.')
    //         {
    //             vector<pair<int,int>> changed;
    //             res[i][j] = 'Q';
    //             for(int r = 0; r < n; r++) {
    //                 if(r != i && res[r][j] == '.') {
    //                     res[r][j] = 'X';
    //                     changed.push_back({r,j});
    //                 }
    //             }
    //             int r = i - 1;
    //             int c = j - 1;
    //             while(r >= 0 && c >= 0) {
    //                 if(res[r][c] == '.') {
    //                     res[r][c] = 'X';
    //                     changed.push_back({r,c});
    //                 }
    //                 r--;
    //                 c--;
    //             }
    //             r = i + 1;
    //             c = j + 1;
    //             while(r < n && c < n) {
    //                 if(res[r][c] == '.') {
    //                     res[r][c] = 'X';
    //                     changed.push_back({r,c});
    //                 }
    //                 r++;
    //                 c++;
    //             }
    //             r = i - 1;
    //             c = j + 1;
    //             while(r >= 0 && c < n) {
    //                 if(res[r][c] == '.') {
    //                     res[r][c] = 'X';
    //                     changed.push_back({r,c});
    //                 }
    //                 r--;
    //                 c++;
    //             }
    //             r = i + 1;
    //             c = j - 1;
    //             while(r < n && c >= 0) {
    //                 if(res[r][c] == '.') {
    //                     res[r][c] = 'X';
    //                     changed.push_back({r,c});
    //                 }
    //                 r++;
    //                 c--;
    //             }
    //             solve(t + 1, i + 1, res, ress, n);

    //             res[i][j] = '.';

    //             for(auto p : changed) {
    //                 res[p.first][p.second] = '.';
    //             }
    //         }
    //     }        
    // }
    // vector<vector<string>> solveNQueens(int n) {
    //     vector<vector<string>> ress;
    //     vector<string> res;
    //     for(int i = 0; i < n; i++){
    //         string s = "";
    //         for(int j = 0; j < n; j++){
    //             s+=".";
    //         }
    //         res.push_back(s);
    //     }
    //     solve(0,0,res,ress,n);

    //     return ress;
    // }
    bool isSafe(int row,int col,vector<string> &board,int n){
        for(int i = 0; i < n; i++){
            if(i != row && board[i][col] == 'Q') return false;
            if(i != col && board[row][i] == 'Q') return false;
        }
        int i = row - 1;
        int j = col - 1;
        while(i >= 0 && j >= 0) {
            if(board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }

        i = row + 1;
        j = col + 1;
        while(i < n && j < n) {
            if(board[i][j] == 'Q')
                return false;
            i++;
            j++;
        }

        i = row - 1;
        j = col + 1;
        while(i >= 0 && j < n) {
            if(board[i][j] == 'Q')
                return false;
            i--;
            j++;
        }

        i = row + 1;
        j = col - 1;
        while(i < n && j >= 0) {
            if(board[i][j] == 'Q')
                return false;
            i++;
            j--;
        }

        return true;
    }
    void solve(int col, vector<string> &board, vector<vector<string>> &ress,vector<int> &leftRow,vector<int> &upperDiag,vector<int> &lowerDiag, int n){
        if(col == n){
            ress.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++){
            if(leftRow[row] == 0 && lowerDiag[row+col] == 0 && upperDiag[n-1+col-row] == 0)
            {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiag[row+col] = 1;
                upperDiag[n-1+col-row] = 1;
                
                solve(col+1,board,ress,leftRow,upperDiag,lowerDiag,n);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiag[row+col] = 0;
                upperDiag[n-1+col-row] = 0;
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ress;
        vector<string> board(n);
        string s(n,'.');
        for(int i = 0; i < n; i++){
            board[i] = s;
        }
        vector<int> leftRow(n,0),upperDiag(2*n-1,0),lowerDiag(2*n-1,0);
        solve(0,board,ress,leftRow,upperDiag,lowerDiag,n);

        return ress;
    }
};