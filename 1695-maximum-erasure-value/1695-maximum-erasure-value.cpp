class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int i=0,j=0;
        int duplicates = 0;
        int currentSum = 0;
        int maxSum = 0;
        unordered_map<int,int> freq;

        while(j<n){
            //duplicate
            if(freq[nums[j]] == 1){
                duplicates++;
            }
            freq[nums[j]]++;
            currentSum += nums[j];

            while(duplicates > 0){
                freq[nums[i]]--;
                currentSum -= nums[i];
                if(freq[nums[i]] == 1){
                    duplicates--;
                }
                i++;
            }

            maxSum = max(maxSum,currentSum);
            j++;
        }

        return maxSum;
    }
};