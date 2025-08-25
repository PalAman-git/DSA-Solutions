class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>> mp;
        int n = mat.size();
        int m = mat[0].size();

        vector<int> result;

        //filling the map
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }

        bool flip = true;
        for(auto &it : mp){
            if(flip){
                reverse(it.second.begin(),it.second.end());
            }
            result.insert(result.end(),it.second.begin(),it.second.end());

            flip = !flip;
        }
        return result;
    }
};