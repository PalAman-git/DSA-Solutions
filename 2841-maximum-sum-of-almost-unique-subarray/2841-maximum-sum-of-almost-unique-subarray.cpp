class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();

        int i=0,j=0;
        long long maxSum = 0;
        long long sum = 0;

        unordered_map<int,int>freq;

        while(j<n){
            freq[nums[j]]++;
            sum += nums[j];

            if(j-i+1 < k){
                j++;
            }else if(j-i+1 == k){
                //do calculation
                if(freq.size() >= m){
                    maxSum = max(maxSum,sum);
                }

                //remove the ith element
                freq[nums[i]]--;
                sum -= nums[i];
                if(freq[nums[i]] == 0) freq.erase(nums[i]);

                i++;
                j++;
            }
        }

        return maxSum;
    }
};