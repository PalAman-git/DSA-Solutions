class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int set_bits[nums.size()];
        for(int i=0;i<nums.size();i++)
        {
            set_bits[i] = __builtin_popcount(nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size()-1-i;j++)
            {
                if(nums[j] > nums[j+1] && set_bits[j] != set_bits[j+1]){
                    return false;
                }
                else if(nums[j] > nums[j+1]){
                    swap(nums[j],nums[j+1]);
                }
            }
        }
        return true;
    }
};