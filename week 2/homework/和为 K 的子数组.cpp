class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        
        unordered_map<int, int> count;
        count[sum[0]]++;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (count.find(sum[i]- k) != count.end()) {
                ans += count[sum[i] - k];
            }
            count[sum[i]]++;
        }

        return ans;
    }
};