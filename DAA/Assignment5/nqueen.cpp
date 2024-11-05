#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col, int n) {
    for(int i=0; i<row; i++)
        if(board[i][col]==1)
            return false;

    for(int i=row, j=col; i>=0 && j>=0; i--,j--)
        if(board[i][j]==1)
            return false;

    for(int i=row, j=col; i>=0 && j<n; i--,j++)
        if(board[i][j]==1)
            return false;

    return true;
}

bool solveNQueens(vector<vector<int>> &board, int row, int n) {
    if(row>=n) return true;

    for(int col=0; col<n; col++) {
        if(isSafe(board, row, col, n)) {
            board[row][col] = 1;
            if(solveNQueens(board, row+1, n)) return true;
            board[row][col] = 0;
        }
    }
    return false;
}

void printBoard(const vector<vector<int>> &board, int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            cout<<(board[i][j] == 1 ? "Q ":". ");
        cout << endl;
    }
}

int main() {
    
    while(true){
        int n;
        cout<<"\nN = ";
        cin>>n;

        vector<vector<int>>board(n,vector<int>(n,0));
        if(solveNQueens(board,0,n)) {
            cout<<"\nOne possible solution:\n";
            printBoard(board,n);
        } else {
            cout<<"\nNo solution exists for "<<n<<" queens.\n";
        }
    }
    return 0;
}

/*
Time: O(N!)
In the worst case, if no conflicts arise, you can place a queen in every column for each row. This gives rise to 
N choices for the first row, N−1 for the second (if the first was successfully placed), and so forth down to 1 for the 
Nth row, leading to a factorial growth: N×(N−1)×(N−2)×...×1=N!.

Space: O(N^2)
*/
