class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        map<int,vector<int>> mp;
        vector<vector<int>> result(n,vector<int>(m,0));

        //filling the map
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i-j].push_back(grid[i][j]);
            }
        }

        //for reversing vector which have keys greater than 0
        for(auto &it : mp){

            //if key is >= 0 , then sort it in desending order
            if(it.first >= 0){
                sort(it.second.begin(),it.second.end(),greater<int>());
            }
            else{
                //if key is < 0 , then sort it in ascending order
                sort(it.second.begin(),it.second.end());
            }
        }

        //filling the result vector
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result[i][j] = mp[i-j][0];
                mp[i-j].erase(mp[i-j].begin());
            }
        }

        return result;
    }
};