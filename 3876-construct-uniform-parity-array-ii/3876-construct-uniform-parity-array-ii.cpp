class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = INT_MAX;

        // Find the smallest odd number
        for (int x : nums1) {
            if (x % 2 == 1) {
                mn = min(mn, x);
            }
        }

        // If an even number is smaller than the smallest odd,
        // we cannot make all elements have the same parity.
        for (int x : nums1) {
            if (x % 2 == 0 && mn != INT_MAX && x < mn) {
                return false;
            }
        }

        return true;
    }
};