class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;

        unordered_map<int, int> freq;
        int distinctSum = 0;
        int minLen = INT_MAX;

        while (j < n) {
            freq[nums[j]]++;
            if(freq[nums[j]] == 1){
                distinctSum += nums[j];
            }

            while(distinctSum >= k){
                minLen = min(minLen,j-i+1);

                freq[nums[i]]--;
                if(freq[nums[i]] == 0){
                    distinctSum -= nums[i];
                }
                i++;
            }
            j++;            
        }

        return minLen == INT_MAX ? -1 : minLen;
    }
};