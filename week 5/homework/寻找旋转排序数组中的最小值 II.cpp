// 每次都和right作比较
class Solution {
public:
    int findMin(vector<int>& nums) {
        int num = nums.size();
        int left = 0;
        int right = num - 1;

        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] < nums[right]) {
                right = mid;
            } else if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right--;              // 等于说明右边界有替代，可以舍弃
            }
        }
        
        return nums[right];
    }
};