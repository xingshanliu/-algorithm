// 求速度最小值：二分答案>=target类型
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1;
        for (auto pile: piles) {
            right = max(right, pile);
        }

        while (left < right) {
            int mid = left + (right - left ) / 2;
            if (valid(piles, h, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right; 
    }

    bool valid(vector<int>& piles, int h, int speed) {
        int costTime = 0;
        for (auto pile: piles) {
            costTime += (pile - 1) / speed + 1;        // 向上取整
        }

        return costTime <= h;
    }
};