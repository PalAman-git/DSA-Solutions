class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long validSubArr = 0;
        int pairs = 0;
        
        int i=0,j=0;
        unordered_map<int,int> freq;

        while(j<n){
            //add nums[j]
            pairs += freq[nums[j]];
            freq[nums[j]]++;

            //shrink while valid
            while(pairs >= k){
                validSubArr += (n-j);

                //remove nums[i]
                freq[nums[i]]--;
                pairs -= freq[nums[i]];
                i++;
            }

            j++;
        }

        return validSubArr;

    }
};