class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int addend = 1;
        for (int i = digits.size() - 1; i >= 0 ; --i) {
            if (addend == 0) {
                break;
            }
            digits[i] += addend;
            addend = digits[i] / 10;
            digits[i] = digits[i] % 10;
        }

        if (addend == 1) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};