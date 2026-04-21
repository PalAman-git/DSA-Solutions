class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int l = 0;
        int maxLen = 0;

        for(int r = 0;r<nums.size();r++){

            while(nums[r] - nums[l] > 1){
                l++;
            }

            if(nums[r] - nums[l] == 1){
                maxLen = max(maxLen,r - l + 1);
            }
        }

        return maxLen;
    }
};