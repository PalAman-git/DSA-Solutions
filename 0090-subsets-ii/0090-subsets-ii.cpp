class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    
    // Using set to store unique subsets
    set<vector<int>> uniqueSubsets;
    int n = nums.size();
    
    // Iterate over all possible subsets (2^n possibilities)
    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<int> subset;
        
        for (int i = 0; i < n; ++i) {
            // Check if the i-th element is included in the subset
            if (mask & (1 << i)) {
                subset.push_back(nums[i]);
            }
        }
        
        // Insert subset into the set to ensure uniqueness
        uniqueSubsets.insert(subset);
    }
    
    // Convert set to vector
    return vector<vector<int>>(uniqueSubsets.begin(), uniqueSubsets.end());
}
};