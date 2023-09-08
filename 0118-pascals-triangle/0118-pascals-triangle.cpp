class Solution {
public:
    vector<int> generateRow(int row)
    {
        long long ans = 1;
        vector<int> v;
        v.push_back(1);//hr row ka phla element 1 hi hota hai

        for(int i=1;i<row;i++)
        {
            ans = ans * (row - i);
            ans = ans / (i);
            v.push_back(ans);
        }
        return v;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for(int i=1;i<=numRows;i++)
        {
            ans.push_back(generateRow(i));
        }
        return ans;             
    }
};