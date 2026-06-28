class Solution {
public:
    int n, m;
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool find(int i, int j, int idx, vector<vector<char>>& board, string& word) {
           if (idx == word.size())
            return true;

        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[idx])
            return false;
    
        char temp = board[i][j];
        board[i][j] = '#';

        for (auto& e : dir) {
            int new_x = i + e[0];
            int new_y = j + e[1];
            if (find(new_x, new_y, idx + 1, board, word)) {
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && find(i, j, 0, board, word))
                    return true;
            }
        }
        return false;
    }
};