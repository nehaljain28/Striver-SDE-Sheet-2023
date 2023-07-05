bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char el='1';el<='9';el++){
                        if(safe(board,i,j,el)){
                            board[i][j]=el;
                            if(solve(board)){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                        
                    }
                    return false;
                }
                
            }
        }
        return true;
    }
    bool safe(vector<vector<char>> &board,int row,int col,int el){
        for(int i=0;i<=8;i++){
            if(board[row][i]==el)return false;
            if(board[i][col]==el)return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==el)return false;
        }
                    return true;

    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
