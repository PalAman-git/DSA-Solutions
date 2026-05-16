class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1e9);

        // reaching index 0 takes 0 jumps as we are alredy standing there
        dp[0] = 0;

        for (int i = 0; i < n; i++){

            for(int jump = 1;jump<= nums[i];jump++){
                int nextIndex = i + jump;

                if(nextIndex < n){
                    dp[nextIndex] = min(dp[nextIndex],1 + dp[i]);
                }
            }
        }

        return dp[n-1];
    }
};