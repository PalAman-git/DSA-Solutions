class Solution {
public:
    // bool isStrictlyIncreasing(vector<int>& nums,int startIdx,int k){
    //     for(int i=0;i<k - 1;i++){
    //         if(nums[startIdx + i] >= nums[startIdx + i+1] )return false;
    //     }
    //     return true;
    // }

    // bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    //     int n = nums.size();

    //     for(int i=0;i <= n - (k*2) ; i++ ){
    //         if(isStrictlyIncreasing(nums,i,k) && isStrictlyIncreasing(nums,i+k,k)) return true;
    //     }
    //     return false;
    // }

    //my first solution O(n*k) , runs for loop k times for every n
    
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2 * k) return false;

        vector<int> inc(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                inc[i] = inc[i - 1] + 1;
        }

        for (int i = k - 1; i + k < n; i++) {
            // Check if the k-length streak ends here and next subarray also has streak of k
            if (inc[i] >= k && inc[i + k] >= k) return true;
        }
        return false;
    }
};
