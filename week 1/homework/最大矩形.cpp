struct rect {
    int height;
    int width;
};

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) {
            return 0;
        }
        int ans = 0;
        int m = matrix[0].size();
        vector<int> heights(m); 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            ans = max(largestRectangleArea(heights), ans);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        heights.push_back(0);
        for(auto height : heights) {
            int accumulation = 0;
            while (!s.empty() && s.top().height >= height) {
                rect topRect = s.top();
                accumulation += topRect.width;
                ans = max(ans, accumulation * topRect.height);
                s.pop();
            }
            struct rect newRect = {height, accumulation + 1};
            s.push(newRect);
        }
        return ans;
    }

private:
    stack<rect> s;
};