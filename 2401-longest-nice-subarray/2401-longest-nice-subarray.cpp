class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int mask = 0;
        int i=0,j=0;

        int window_size = INT_MIN;

        while(j<n){
            if((mask & nums[j]) == 0){
                //if there is no conflict
                mask |= nums[j]; //add nums[j] to mask
                window_size = max(window_size,j-i+1); //find the max size
                j++; //expand the window
            }else{
                //remove the nums[i] till the conflict resolves
                while((mask & nums[j]) != 0){
                    mask ^= nums[i]; //remove bits of nums[i] from mask
                    i++; // shrink the window
                }
            }
        }

        return window_size;
    }
};