class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0, j = 0;
        int ans = 0;
        int odd = 0;

        while (j < n) {
            // include jth element
            if (nums[j] % 2 == 1)
                odd++;

            while (odd > k) {
                if (nums[i] % 2 == 1)
                    odd--;
                i++;
            }

            ans += (j - i + 1);
            j++;
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};