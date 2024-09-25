class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> geneBank(bank.begin(),bank.end());
        vector<char> alphabets = {'A','C','G','T'};
        queue<pair<string,int>> q;
        q.push({startGene,0});

        while(!q.empty())
        {
            string gene = q.front().first;
            int mutation = q.front().second;
            q.pop();

            if(gene == endGene) return mutation;

            for(int i=0;i<gene.size();i++)
            {
                char original = gene[i];

                for(auto ch : alphabets)
                {
                    gene[i] = ch;

                    if(geneBank.count(gene))
                    {
                        q.push({gene,mutation+1});
                        geneBank.erase(gene);   
                    }
                }
                gene[i] = original;
            }
        }
        return -1;
    }
};