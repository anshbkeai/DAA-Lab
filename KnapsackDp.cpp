#include<iostream>
//#include<math>
#include<algorithm>

using  namespace std;
int knapsack(int  n  ,  int  W, int wt[],  int val[]) {
    int  dp[n+1][W+1];
    for(int i   = 0 ; i <= n ; i++) dp[i][0] = 0;
    for(int  i  = 0 ; i <=W;i++)  dp[0][i]   = 0;
    
    for(int i  = 1; i <=n ;i++) {
        for(int j =1;j<=W;j++ ) {
            int  v =  val[i-1];
            int w  =  wt[i-1]; // Gettig  the  Weight  of  the   Value  at  the   Actual  Index 
            
            if (w <= j) {
                    int incProfit = v + dp[i - 1][j - w];
                    int excProfit = dp[i - 1][j];
                    dp[i][j] = max(incProfit, excProfit);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
           
        }
    }

    //  Printin  the   Item  Choose 
    int i =  n;int j  = W;
    while(i>0 &&  j>0) {
        if(dp[i][j]  !=  dp[i-1][j]) {
            cout<<"Item  Selected -Weight" <<wt[i-1] << " -Value "<<val[i-1]<<endl;
            i = i-1;
            j  =  j-wt[i-1];
        }
        else {
            i--;    
        }
    }
    return  dp[n][W];
}
int main() {
//    cout<<"Hey User  Solving  the  0/1  Knapsack  "<<endl;
//    int  n;
//    cout<<"Enter  the   Value of  the No of  the   item "<<endl;
//    cin>>n;
//    int  W ;
//    cout<<"Enter  the   Weight of  the   Final  Bag";  cin>>W;
//    int  wt[n]  ;
//    int  val[n];
//    cout<<"Enter  the  Inforamtion "<<endl;
//    for(int  i  = 0 ; i <  n  ;i++) {
//        cin>>wt[i];
//        cin>>val[i];
//    }
//    
//    int  ans  =  knapsack(n,W,wt,val);
//    cout<<ans;
    int choice;
    do {
        cout << "\n===== 0/1 Knapsack Problem Solver =====" << endl;
        cout << "1. Solve Knapsack Problem" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int n;
                cout << "Enter the number of items: ";
                cin >> n;
                int W;
                cout << "Enter the weight capacity of the bag: ";
                cin >> W;
                int wt[n], val[n];
                cout << "Enter the weights and values of the items:" << endl;
                for (int i = 0; i < n; i++) {
                    cout << "Item " << i + 1 << " - Weight: ";
                    cin >> wt[i];
                    cout << "Item " << i + 1 << " - Value: ";
                    cin >> val[i];
                }
                int ans = knapsack(n, W, wt, val);
                cout << "The maximum value that can be obtained: " << ans << endl;
                break;
            }
            case 2:
                cout << "Exiting the program. Have a great day!" << endl;
                break;
            default:
                cout << "Invalid choice! Please enter 1 to solve or 2 to exit." << endl;
        }
    } while (choice != 2);
    return 0;
    /*

    1. Solve Knapsack Problem
2. Exit
Enter your choice: 1
Enter the number of items: 5
Enter the weight capacity of the bag: 56
Enter the weights and values of the items:
Item 1 - Weight: 56
Item 1 - Value: 5
Item 2 - Weight: 12
Item 2 - Value: 5
Item 3 - Weight: 42
Item 3 - Value: 56
Item 4 - Weight: 5
Item 4 - Value: 556
Item 5 - Weight: 6
Item 5 - Value: 66
Item  Selected -Weight6 -Value 66
Item  Selected -Weight5 -Value 556
The maximum value that can be obtained: 678

===== 0/1 Knapsack Problem Solver =====
1. Solve Knapsack Problem
2. Exit
Enter your choice: 

*/

}
