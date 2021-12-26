// 解法1：记忆化搜索
class Solution {
public:
    int climbStairs(int n) {
        toEnd.assign(n + 1, -1);
        return dfs(n);
    }

    int dfs(int n) {
        if (n < 0) {
            return 0;
        }

        if (n == 0) {
            return 1;
        }

        if (toEnd[n] != -1) {
            return toEnd[n];
        }

        toEnd[n] = dfs(n - 1) + dfs(n - 2);
        return toEnd[n];
    }
    vector<int> toEnd;
};

// 解法2：递推
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        } 
        vector<int> startTo(n + 1, 0);
        startTo[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (i - 1 >= 0) {
                startTo[i] += startTo[i - 1];
            } 
            if (i - 2 >= 0) {
                startTo[i] += startTo[i - 2];
            } 
        }
        return startTo[n];
    }  
};