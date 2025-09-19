class Spreadsheet {
    int rows;
    vector<vector<int>> grid;

    pair<int,int> parseCell(const string &cell){
        char colChar = cell[0]; //column letter
        int col = colChar - 'A'; //0 indexed column
        int row = stoi(cell.substr(1))-1; //0 indexed row

        return {row,col};
    }

    int getCellValue(const string &cell){
        auto [row,col] = parseCell(cell);
        if(row < 0 || row > rows) return 0; //out of range -> 0
        return grid[row][col];
    }

public:
    //initializing the 2d vector
    Spreadsheet(int r) : rows(r) {
       grid.assign(rows,vector<int>(26,0));
    }
    
    //set cell to the given value
    void setCell(string cell, int value) {
        auto [row,col] = parseCell(cell);
        if(row >= 0 && row < rows){
             grid[row][col] = value;
        }
    }
    
    //Reset Cell to 0
    void resetCell(string cell) {
        auto [row,col] = parseCell(cell);
        if(row >= 0 && row < rows){
            grid[row][col] = 0;
        }
    }
    
    //Evaluate formula of form "=X+Y"
    int getValue(string formula) {
        if(formula.empty() || formula[0] != '=')return 0;

        string expr = formula.substr(1); //removes '='
        size_t plusPos = expr.find('+');
        string left = expr.substr(0,plusPos);//selects the string before '='
        string right = expr.substr(plusPos + 1);//selects the string after '='

        int leftVal , rightVal;

        if(isalpha(left[0])) leftVal = getCellValue(left);
        else leftVal = stoi(left);

        if(isalpha(right[0])) rightVal = getCellValue(right);
        else rightVal = stoi(right);

        return leftVal + rightVal;

    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */