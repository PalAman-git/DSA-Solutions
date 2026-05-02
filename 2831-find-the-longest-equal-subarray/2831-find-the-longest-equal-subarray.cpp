class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,vector<int>> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        int ans = 0;
        for(auto& [val,pos] : mp){
            
            int i = 0;

            for(int j=0;j<pos.size();j++){
                while((pos[j] - pos[i] + 1) - (j - i + 1) > k){
                    i++;
                }

                ans = max(ans,j-i+1);
            }

        }

        return ans;
    }
};