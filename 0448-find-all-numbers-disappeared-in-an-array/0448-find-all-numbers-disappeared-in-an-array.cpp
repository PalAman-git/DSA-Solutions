class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1,1);

        freq[0] = 0;

        for(int i=0;i<n;i++){
            freq[nums[i]]--;
        }

        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(freq[i] == 1) ans.push_back(i);
        }

        return ans;
    }
};