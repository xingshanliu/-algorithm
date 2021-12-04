//解法一：哈希去重
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        num = nums.size();
        picked.assign(num, false);
        dfs(nums);
        return ans;
    }

    void dfs(vector<int>& nums) {
        if (chosen.size() >= num) {
            string hashStr = calhash(chosen);
            if (s.find(hashStr) == s.end()) {
                ans.push_back(chosen);
                s.insert(hashStr);
            }
            return;
        }

        for (int i = 0; i < num; i++) {
            if (!picked[i]) {
                picked[i] = true;
                chosen.push_back(nums[i]);
                dfs(nums);
                picked[i] = false;
                chosen.pop_back();
            }
        }
    }

    string calhash(vector<int> &chosen) {
        string hashStr;
        for (auto num : chosen) {
            hashStr.append(to_string(num) + ".");
        }

        return hashStr;
    }
    int num;
    vector<vector<int>> ans;
    vector<int> chosen;
    vector<bool> picked;
    unordered_set<string> s;
};

//解法2：排序+前后两个数比较
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        num = nums.size();
        picked.assign(num, false);
        sort(nums.begin(), nums.end());
        dfs(nums);
        return ans;
    }

    void dfs(vector<int>& nums) {
        if (chosen.size() >= num) {
            ans.push_back(chosen);
            return;
        }

        for (int i = 0; i < num; i++) {
            if (picked[i] || i > 0 && nums[i] == nums[i - 1] && !picked[i - 1]) {
                continue;
            }
            
            picked[i] = true;
            chosen.push_back(nums[i]);
            dfs(nums);
            picked[i] = false;
            chosen.pop_back();
        }
    }

    int num;
    vector<vector<int>> ans;
    vector<int> chosen;
    vector<bool> picked;
};