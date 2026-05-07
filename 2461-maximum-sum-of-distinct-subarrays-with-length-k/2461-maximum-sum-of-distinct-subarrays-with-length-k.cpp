class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int i=0,j=0;
        int duplicates=0;
        long long sum = 0, maxSum = INT_MIN;

        unordered_map<int,int> freq;

        while(j < n){
            //if already 1 nums[j] present means it is duplicate
            if(freq[nums[j]] == 1){
                duplicates++;
            }

            freq[nums[j]]++;
            sum += nums[j];

            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){

                if(duplicates == 0){
                    maxSum = max(maxSum,sum);
                }

                //remove ith element
                sum -= nums[i];
                freq[nums[i]]--;
                if(freq[nums[i]] == 1){
                    duplicates--;
                }
                

                //move the window
                i++;
                j++;
            }
            
        }

        return maxSum == INT_MIN ? 0 : maxSum;
    }
};