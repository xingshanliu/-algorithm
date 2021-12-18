// 二维转换为一维，二分查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0;
		int right = row * col - 1;
        
        while (left <= right) {
            int mid = (left + right) >> 1;
            int curRow = mid / col;
            int curCol = mid % col;
            if (matrix[curRow][curCol] == target) {
                return true;
            } else if (matrix[curRow][curCol] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};