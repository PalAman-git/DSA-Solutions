class Solution {
public:
    unordered_map<int,int> dp;
    int solve(int i, vector<int>& nums) {

        if(dp.find(i) != dp.end()) return dp[i];

        int n = nums.size();

        if (i >= n - 1)
            return 0;

        int ans = 1e9;
        for (int jump = 1; jump <= nums[i]; jump++) {
            ans = min(ans, 1 + solve(i + jump, nums));
        }

        dp[i] = ans;
        return ans;
    }
    int jump(vector<int>& nums) { return solve(0, nums); }
};