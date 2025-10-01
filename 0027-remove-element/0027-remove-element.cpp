class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int k = n;
        vector<int> result;

        for(int i = 0;i<n;i++){
            if(nums[i] == val){
                k--;
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i] != val){
                result.push_back(nums[i]);
            }
        }

        nums = result;
        return k;
    }
};