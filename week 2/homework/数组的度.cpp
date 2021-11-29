class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> start, end, count;
        int n = nums.size();
        int maxDegree = 0;
        for (int i = 0; i < n; i++) {
            if (start.find(nums[i]) == start.end()) {
                start[nums[i]] = i;
            }

            end[nums[i]] = i;
            count[nums[i]]++;
            maxDegree = max(count[nums[i]], maxDegree);
        }

        int ans = n;
        for (auto &degree : count) {
            if (degree.second == maxDegree) {
                ans = min(ans,  end[degree.first] - start[degree.first] + 1);
            }
        }

        return ans;
    }
};