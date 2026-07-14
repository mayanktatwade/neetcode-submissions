class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;   // We are adding 1

        for (int i = digits.size() - 1; i >= 0; i--) {
            int temp = digits[i] + carry;

            if (temp >= 10) {
                digits[i] = temp % 10;
                carry = 1;
            } else {
                digits[i] = temp;
                carry = 0;
                break;
            }
        }

        if (carry) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};