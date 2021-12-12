// 思路：从边界拓展，把拓展的点标记为'$', 剩余的'O'就可以标记为'X'，最后再将'$'改为‘O’
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        row = board.size();
        col = board[0].size();
        visited.assign(row, vector<bool>(col, false));

        for (int x = 0; x < row; x++) {
            for (int y = 0; y < col; y++) {
                if (!visited[x][y] && (x == 0 || y == 0 || x == row - 1 || y == col -1) && board[x][y] == 'O') {
                    dfs(board, x, y, '$');    
                }
            }
        }

        for (int x = 0; x < row; x++) {
            for (int y = 0; y < col; y++) {
                if (board[x][y] == '$') { 
                    board[x][y] = 'O';
                } else if (board[x][y] == 'O'){
                    board[x][y] = 'X';
                }
            }
        }

    }

    void dfs(vector<vector<char>>& board, int x, int y, char ch) {
        visited[x][y] = true;
        board[x][y] = ch;
        for (int direct = 0; direct < 4; direct++) {
            int nx = x + dx[direct];
            int ny = y + dy[direct];
            if (nx < 0 || nx >= row || ny < 0 || ny >= col || visited[nx][ny] || board[nx][ny] != 'O') {
                continue;
            }
            dfs(board, nx, ny, ch);
        }
    }
    int row;
    int col;
    const int dx[4] = {0, 0, -1, 1};
    const int dy[4] = {1, -1, 0, 0}; 
    vector<vector<bool>> visited;
};