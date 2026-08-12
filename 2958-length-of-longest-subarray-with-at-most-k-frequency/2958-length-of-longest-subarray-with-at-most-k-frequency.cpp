 class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k)
    {
        unordered_map<int,int> freq;

        int low = 0;
        int ans = 0;

        for(int high = 0; high < nums.size(); high++)
        {
            freq[nums[high]]++;

            while(freq[nums[high]] > k)
            {
                freq[nums[low]]--;

                low++;
            }

            ans = max(ans, high - low + 1);
        }

        return ans;
    }
};