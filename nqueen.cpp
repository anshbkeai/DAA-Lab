#include<iostream>
#include<algorithm>

using namespace  std;

void printBoard(int x[], int n) {
    
    char  board[n][n];
    for(int  i  = 0 ;i < n ;i++) {
            for(int j  =0;j<n;j++) board[i][j] = '.';
    }
    for(int i = 1 ; i <=  n ;i++) {
        board[i-1][x[i]] = 'Q';
    }    
    
    for(int i  = 0 ; i < n ;i++) {
        for(int j  = 0  ;j<n ;j++) {
                cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool  Place(int k , int i , int x[] ) {
        for(int j  = 1 ; j <k;j++) {
            if(x[j] == i  || abs(x[j]-i) == abs(j-k) ) return false;
        }
        return  true;
}
void Nqueen(int  k , int  n , int x[]) {
    for(int  i = 0 ; i < n ;i++ ) {
            if(Place(k,i,x)) {
                x[k]   = i;
                if(k==n) {
                    for(int i  = 1 ; i < n+1 ;i++) cout<<x[i] << "  ";
                    cout<<"One of  the  ArrangeMent fo  the  Board "<<endl;
                    printBoard(x,n);
                    cout<<endl; 
                }
                Nqueen(k+1,n,x);
            }
            
    }
}
void Nqueen(int n ) {
      int  ans[n+1] = {0};
      Nqueen(1,n,ans);
//if  you  Want a  2d mTRIC
    //for(int i  = 0 ; i < n+1 ;i++) cout<<ans[i] << "  "; 
}
int  main() {
    int n;
    cout << "Enter the size of the chessboard (N for N-Queens): ";
    cin >> n;

    if (n < 1) {
        cout << "Invalid board size! Please enter a positive integer." << endl;
    } else {
        cout << "Solving the " << n << "-Queens problem...  and   Printing  the   Board" << endl;
        Nqueen(n);
    }

}
/*
The N-Queens implementation correctly uses backtracking to place queens while ensuring no conflicts.

The printBoard() function efficiently displays the board, but array indexing should be consistent to avoid confusion.

The function Place() checks column and diagonal conflicts efficiently, ensuring correctness.

The recursive Nqueen() function correctly generates all solutions, but printing could be cleaner for readability.

Time Complexity: 𝑂(𝑁!)
O(N!) due to the exponential nature of backtracking,
Space Complexity: O(N) for recursion depth and array storage.


*/
