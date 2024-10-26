class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //using the max heap(NlogN)
        // unordered_map<int,int> mp;
        // for(int i=0;i<nums.size();i++)
        // {
        //     mp[nums[i]]++;
        // }
        // priority_queue<pair<int,int>> pq;

        // for(const auto &it : mp)
        // {
        //     pq.push({it.second,it.first});
        // }
        
        // vector<int> ans;
        // for(int i=0;i<k;i++)
        // {
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }
        // return ans;

        //using the bucket sort
        unordered_map<int,int> mp;
        for(auto &it : nums)
        {
            mp[it]++;
        }

        vector<vector<int>> bucket(nums.size()+1);
        for(const auto &it : mp)
        {
            int i = it.second;
            int value = it.first;

            bucket[i].push_back(value);
        }

        vector<int> ans;
        for(int i=bucket.size()-1;i>=0;i--)
        {
           for(int &num : bucket[i])
           {
            ans.push_back(num);
            if(ans.size() == k) return ans;
           }
        }
        return {0};
    }
};