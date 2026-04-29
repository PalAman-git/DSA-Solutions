class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int i=0,j=0;
        int max_window = INT_MIN;

        unordered_map<int,int> freq;

        while(j<n){
            freq[nums[j]]++;

            while(freq[nums[j]] > k){
                freq[nums[i]]--;
                i++;
            }

            max_window = max(max_window,j-i+1);
            j++;
        }

        return max_window;
    }
};