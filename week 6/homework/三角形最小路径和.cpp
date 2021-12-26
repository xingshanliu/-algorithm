class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> minSum(m, vector<int>(m, 0));
        minSum[0][0] = triangle[0][0];
        for (int i = 1; i < m; i++) {
            minSum[i][0] = minSum[i - 1][0] + triangle[i][0]; // 处理每层最左元素
            for (int j = 1; j < i; j++) {
                minSum[i][j] = min(minSum[i - 1][j], minSum[i - 1][j - 1]) + triangle[i][j];
            }
            minSum[i][i] = minSum[i - 1][i - 1] + triangle[i][i]; // 处理每层最右元素
        }
        int ans = 1e+5;
        for (int i = 0; i < m; i++) {
            ans = min(minSum[m - 1][i], ans);
        }

        return ans;
    }
};