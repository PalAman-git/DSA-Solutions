class Solution {
public:
    bool search(vector<int> &stones,int key)
    {
        int low = 0;
        int high = stones.size() - 1;

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            if(stones[mid] == key) return true;

            else if(key > stones[mid])
            {
                low = mid + 1;
            }
            else if(key < stones[mid])
            {
                high = mid - 1;
            }
        }
        return false;
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int,set<int>> mp;
        
        mp[0].insert(1);

        for(int i=0;i<stones.size();i++)
        {
            int currStone = stones[i];
            set<int> jumps = mp[currStone];//get the jump options

            for(auto jump : jumps)
            {
                //finding the curr position
                int pos = currStone + jump;
                if(pos == stones[stones.size()-1]) return true;
                if(search(stones,pos) == true)
                {
                    //0 or negative jump should not be considered
                    if(jump - 1 > 0)
                    {
                        mp[pos].insert(jump - 1);
                    }
                    mp[pos].insert(jump);
                    mp[pos].insert(jump + 1);
                }
            }
        }
        return false;
    }
};