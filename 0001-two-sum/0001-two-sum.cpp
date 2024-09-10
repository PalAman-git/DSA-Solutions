class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //it can be done with the time complexity of nlogn by first sorting the array
        //and then using 2 pointers i and j if target is less then arr[i] + arr[j] greater,
        //decrease the j and if the sum is less then increase i and find the pair

        //this approach do this in n time and n space complexity

        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target - nums[i]) == mp.end())
            {
                mp[nums[i]] = i;
            }
            else
            {
                return {mp[target - nums[i]],i};
            }
        }
        return {-1,-1};
    }
};