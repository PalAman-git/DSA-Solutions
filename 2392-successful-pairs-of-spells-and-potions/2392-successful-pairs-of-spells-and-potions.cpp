class Solution {
public:
    int binary_search(vector<int>& potions,int spell,long long success){
        int low = 0;
        int high = potions.size() - 1;
        

        while(low <= high){
            int mid = low + (high - low)/2;

            if(1LL * potions[mid] * spell  >= success){
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }

        return potions.size() - low;//gives the potions , which on multiplying with spell >= success
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(),potions.end());
        vector<int> arr;

        for(int i=0;i<n;i++){
            arr.push_back(binary_search(potions,spells[i],success));
        }
        
        return arr;
    }
};