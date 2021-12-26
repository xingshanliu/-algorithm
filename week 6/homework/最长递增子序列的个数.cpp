class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int num = nums.size();
        int maxLen = 0;
        int ans = 0;
        vector<int> lis(num, 1);
        vector<int> lisCount(num, 1);

        for (int i = 0; i < num; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (lis[j] + 1 > lis[i]) {
                        lis[i] = lis[j] + 1;
                        lisCount[i] = lisCount[j]; 
                    } else if (lis[j] + 1 == lis[i]) {
                        lisCount[i] += lisCount[j];
                    }
                }
            }

            if (lis[i] > maxLen) {
                maxLen = lis[i];
                ans = lisCount[i]; 
            } else if (lis[i] == maxLen) {
                ans += lisCount[i];
            }
        }

        return ans;
    }
};