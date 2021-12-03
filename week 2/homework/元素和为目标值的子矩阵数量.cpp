class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        int ans =0;
        sums.resize(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sums[i][j] =  sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] + matrix[i - 1][j -1];
            }
        }
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                for(int p = 1; p <= i; p++) {
                    for(int q = 1; q <= j; q++) {
                        if (sums[i][j] - sums[p - 1][j] - sums[i][q - 1] + sums[p - 1][q - 1] == target) ans++;
                    }
                }
            }
        }
        return ans;
    }
private:
    vector<vector<int>> sums;
};