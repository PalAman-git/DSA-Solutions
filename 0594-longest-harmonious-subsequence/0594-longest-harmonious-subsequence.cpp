class Solution {
public:
    int findLHS(vector<int>& nums) {

        //O(n)
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        int result = 0;
        for(auto &it : mp){
            int key = it.first;

            if(mp.count(key+1)){
                result = max(result,mp[key] + mp[key+1]);
            }
        }

        return result;


        //O(nlogn)
        // sort(nums.begin(),nums.end());

        // int l = 0;
        // int maxLen = 0;

        // for(int r = 0;r<nums.size();r++){

        //     while(nums[r] - nums[l] > 1){
        //         l++;
        //     }

        //     if(nums[r] - nums[l] == 1){
        //         maxLen = max(maxLen,r - l + 1);
        //     }
        // }

        // return maxLen;
    }
};