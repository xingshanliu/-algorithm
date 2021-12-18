// 二分答案求最小值
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 500;
        int right = 0;
        for (auto weight : weights) {
            left = min(left, weight);    
            right += weight; 
        }

        while (left < right) {
            int mid = (left + right) >> 1;
            if (valid(weights, days, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return right;
    }

    bool valid(vector<int>& weights, int days, int cap) {
        int costDay = 1;
        int curWeight = 0;
        for (auto weight : weights) {
            if (weight + curWeight <= cap) {
                curWeight += weight;
            } else {
                if (weight > cap) {
                    return false;;
                }
                curWeight = weight;
                costDay++;
            }
        }

        return costDay <= days;
    }
};