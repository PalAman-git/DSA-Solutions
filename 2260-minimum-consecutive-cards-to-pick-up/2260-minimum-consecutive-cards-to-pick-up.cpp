class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        int i=0,j=0;
        int ans = INT_MAX;
        unordered_map<int,int> freq;

        while(j<n){
            freq[cards[j]]++;

            while(freq[cards[j]] >= 2){
                if(freq[cards[j]] == 2){
                    ans = min(ans,j-i+1);
                }

                //remove ith element
                freq[cards[i]]--;
                i++;
            }
            j++;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};