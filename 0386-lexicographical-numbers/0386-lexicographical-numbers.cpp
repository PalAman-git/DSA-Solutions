class Solution {
public:
    void solve(int currNumber,int n,vector<int> &result)
    {
        if(currNumber > n) return ;

        result.push_back(currNumber);
        for(int append=0;append<=9;append++)
        {
            int newNumber = currNumber*10 + append;
            if(newNumber > n) return;

            solve(newNumber,n,result);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for(int i=1;i<=9;i++)
        {
            solve(i,n,result);
        }
        return result;
    }
};