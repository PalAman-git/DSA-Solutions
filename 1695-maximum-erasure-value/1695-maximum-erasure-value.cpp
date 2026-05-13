class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int i=0,j=0;
        int currentSum = 0;
        int maxSum = 0;
        unordered_map<int,int> freq;

        while(j<n){
            freq[nums[j]]++;
            currentSum += nums[j];

            while(freq[nums[j]] > 1){
                freq[nums[i]]--;
                currentSum -= nums[i];
                i++;
            }

            maxSum = max(maxSum,currentSum);
            j++;
        }

        return maxSum;
    }
};