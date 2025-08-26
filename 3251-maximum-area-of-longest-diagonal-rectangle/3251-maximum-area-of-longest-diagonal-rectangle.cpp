class Solution {
public:
    double diagonal_func(int l,int b){
        return sqrt(l*l + b*b);
    }

    int area_func(int l,int b){
        return l*b;
    }

    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        pair<double,int> p(INT_MIN,INT_MIN);

        for(int i=0;i<n;i++){
            int l = dimensions[i][0];
            int b = dimensions[i][1];

            double diagonal = diagonal_func(l,b);
            int area = area_func(l,b);

            if(diagonal > p.first){
                p.first = diagonal;
                p.second = area;
            }

            if(diagonal == p.first){
                p.second = max(p.second,area);
            }
        }
        return p.second;
    }
};