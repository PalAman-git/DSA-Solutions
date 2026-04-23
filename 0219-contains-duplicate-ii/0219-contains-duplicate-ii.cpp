class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> mp;
        int window_size = k + 1;
        int i=0,j=0;

        while(j < n){
            //do the calculation
            mp[nums[j]]++;
            if(mp[nums[j]] > 1) return true;

            if(j-i+1 < window_size){
                j++;
            }
            else if(j-i+1 == window_size){
                //calculate the ans
                

                //remove ith element
                mp[nums[i]]--;

                //slide the window
                i++;
                j++;
            }
        }

        return false;
    }
};