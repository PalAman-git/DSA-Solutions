class Solution {
public:
   bool util(vector<int> &stones, unordered_map<int, unordered_map<int, bool>> &mp, int pos, int units) {
        if(pos == stones.back()) return true;
        if(mp.find(pos) != mp.end() && mp[pos].find(units) != mp[pos].end()) return mp[pos][units];

        for(int i = units-1; i <= units+1; i++){
            if(i>0){
                int next_pos = pos + i;
                if(binary_search(stones.begin(), stones.end(), next_pos) && util(stones, mp,next_pos, i))
                {
                    mp[pos][units] = true;
                    return true;
                }
            }
        }
        return mp[pos][units] = false;       
    }

    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_map<int, bool>> mp;
        if (stones[1] != 1) return false;
        return util(stones, mp, 1, 1);
    }
};