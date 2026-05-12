class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int i=0,j=0;
        int maxFruits = 0;

        unordered_map<int,int> freq;

        while(j<n){
            freq[fruits[j]]++;

            while(freq.size() > 2){
                freq[fruits[i]]--;

                if(freq[fruits[i]] == 0) freq.erase(fruits[i]);
                i++;
            }

            maxFruits = max(maxFruits,j-i+1);
            j++;
        }

        return maxFruits;
    }
};