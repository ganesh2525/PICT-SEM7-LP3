#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row,int col,int n,vector<vector<int>>&board){
    for(int i=row,j=col; i>=0 && j>=0; i--,j--){
        if(board[i][j]==1) return false;
    }

    for(int i=row,j=col; i>=0 && j<n; i--,j++){
        if(board[i][j]==1) return false;
    }

    for(int i=0; i<row; i++){
        if(board[i][col]==1) return false;
    }

    return true;
}

bool solve(int row,int n,vector<vector<int>>&board){
    if(row==n) return true;

    for(int col=0;col<n;col++){
        if(isSafe(row,col,n,board)){
            board[row][col]=1;
            if(solve(row+1,n,board)) return true;
            board[row][col]=0;
        }
    }
    return false;
}

void printBoard(int n,vector<vector<int>>&board){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==1) cout<<"Q ";
            else cout<<". ";
        }
        cout<<endl;
    }
}

int main(){
    while(true){
        int n;
        cout<<"\nN = ";
        cin>>n;

        vector<vector<int>>board(n,vector<int>(n,0));
        if(solve(0,n,board)){
            printBoard(n,board);
        }
        else{
            cout<<"\nNo solution"<<endl;
        }
    }
    return 0;
}