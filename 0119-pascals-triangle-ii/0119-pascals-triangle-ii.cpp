class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ds;
        long long ans=1;
        ds.push_back(ans);
    
        for(int i=0;i<rowIndex;i++)
        {
            ans=ans*(rowIndex-i);
            ans=ans/(i+1);
            ds.push_back(ans);
        }
        return ds;
    }
};