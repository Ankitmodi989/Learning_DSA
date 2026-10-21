class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

            int start = 0;
            int end = n - 1;
            while (start <= end) {
                int mid = start + (end - start) / 2;

                int row = 0;
                for (int i = 0; i < m; i++) {
                    if (mat[i][mid] > mat[row][mid]) {
                        row = i;
                    }
                }

                int left_val = (mid - 1 >= 0) ? mat[row][mid - 1] : -1;
                int right_val = (mid + 1 < n) ? mat[row][mid + 1] : -1;

                if (mat[row][mid] > left_val &&
                    mat[row][mid] > right_val) {
                    return {row, mid};
                }
                else if (left_val > mat[row][mid]) {
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
        return {-1, -1};
    }
};