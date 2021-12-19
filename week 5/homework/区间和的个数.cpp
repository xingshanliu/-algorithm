class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        count = 0;
        lowerBound = lower;
        upperBound = upper;
        int num = nums.size();
        preSum.assign(num + 1, 0);
        for (int i = 1; i <= num; i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        mergeSort(preSum, 1, nums.size());
        return count;
    }

    void getAns(vector<long long>& preSum, int l, int mid, int r) {
        int start = mid + 1;
        int end = mid + 1;
        while (l <= mid) {
            while (start <= r && preSum[start] - preSum[l] < lowerBound) start++;
            while (end <= r && preSum[end] - preSum[l] <= upperBound) end++;
            count += (end - start);
            l++;
        }
    }

    void mergeArray(vector<long long>& preSum, int l, int mid, int r) {
        int totalLen = r - l + 1;
        int *tmpArray = new int[totalLen];

        int i = l;
        int j = mid + 1;
        for (int k = 0; k < totalLen; k++) {
            if (j > r || i <= mid && preSum[i] <= preSum[j]) {
                tmpArray[k] = preSum[i++];
            } else {
                tmpArray[k] = preSum[j++];
            }
        }

        for (int k = 0; k < totalLen; k++) {
            preSum[l + k] = tmpArray[k];
        } 
        delete[] tmpArray;
    }
    
    void mergeSort(vector<long long>&preSum, int l, int r) {
        if (l >= r) { 
            return;
        }

        int mid = (l + r) >> 1;
        mergeSort(preSum, l, mid);
        mergeSort(preSum, mid + 1, r);
        getAns(preSum, l, mid, r);
        mergeArray(preSum, l, mid, r);
    } 
    
    int count;
    int lowerBound;
    int upperBound;
    vector<long long> preSum;
};