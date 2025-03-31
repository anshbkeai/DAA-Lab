import java.sql.*;
import java.util.Scanner;

/*
 * /*
 * MySQL JDBC Driver Installation & Configuration Guide
 * ----------------------------------------------------
 * This application uses MySQL as its database. Before running the program, 
 * ensure that the MySQL JDBC driver (Connector/J) is installed on your system.
 * 
 * ✅ **1. Installation Instructions for Different OS**
 *
 * 👉 **Windows (PowerShell)**
 *    - Download MySQL Connector/J:
 *      Invoke-WebRequest -Uri "https://dev.mysql.com/get/Downloads/Connector-J/mysql-connector-java-8.0.33.zip" -OutFile "mysql-connector-java.zip"
 *    - Extract the ZIP file and copy the `mysql-connector-java-8.0.33.jar` file to your project directory.
 *    - Add the JAR to your classpath when compiling and running:
 *      ```
 *      javac -cp .;mysql-connector-java-8.0.33.jar Banking.java
 *      java -cp .;mysql-connector-java-8.0.33.jar Banking
 *      ```
 *
 * 👉 **macOS (Homebrew)**
 *    - Install MySQL Connector:
 *      ```
 *      brew install mysql-connector-c
 *      ```
 *    - After installation, find the JAR file and add it to your project.
 *    - Compile and run with:
 *      ```
 *      javac -cp .:/usr/local/share/java/mysql-connector-java.jar Banking.java
 *      java -cp .:/usr/local/share/java/mysql-connector-java.jar Banking
 *      ```
 *
 * 👉 **Linux (Ubuntu/Debian)**
 *    - Install MySQL Connector/J:
 *      ```
 *      sudo apt-get install libmysql-java
 *      ```
 *    - The JAR is usually located at `/usr/share/java/mysql-connector-java.jar`.
 *    - Compile and run with:
 *      ```
 *      javac -cp .:/usr/share/java/mysql-connector-java.jar Banking.java
 *      java -cp .:/usr/share/java/mysql-connector-java.jar Banking
 *      ```
 *
 * ✅ **2. Classpath Configuration**
 *    If you’re using an IDE (e.g., VS Code, Eclipse, IntelliJ), manually add the JAR file:
 *    - In **Eclipse**, go to **Project Properties** → **Java Build Path** → **Libraries** → **Add External JARs**.
 *    - In **IntelliJ**, go to **Project Structure** → **Modules** → **Dependencies** → **Add JARs or Directories**.
 *
 */

public class Banking {

  

   // private  static    Statement statement;
    private static final String url = "jdbc:mysql://localhost:3306/bank";
    private  static final  String user = "root";
    private  static final  String password = "Java@123";
  //  private  static  Connection  connection ;

    private static  Statement  get_statement()  throws  SQLException {
       // Class.forName("com.mysql.cj.jdbc.Driver"); 
      // DriverManager.registerDriver(new com.mysql.jdbc.Driver());
        Connection  connection  =DriverManager.getConnection(url, user, password);
        Statement statement  =  connection.createStatement();
        return  statement;
    }

    private static void setupDb() {
        try {
            Statement statement = get_statement();
    
            // Create User Table
            String createUserTable = "CREATE TABLE IF NOT EXISTS user ("
                    + "id INT AUTO_INCREMENT PRIMARY KEY, "
                    + "name VARCHAR(100) NOT NULL, "
                    + "password VARCHAR(100) NOT NULL)";
            statement.executeUpdate(createUserTable);
    
            // Create Accounts Table
            String createAccountsTable = "CREATE TABLE IF NOT EXISTS accounts ("
                    + "id INT PRIMARY KEY, "
                    + "balance DOUBLE DEFAULT 0, "
                    + "no VARCHAR(20) UNIQUE, "
                    + "location VARCHAR(100), "
                    + "FOREIGN KEY (id) REFERENCES user(id) ON DELETE CASCADE)";
            statement.executeUpdate(createAccountsTable);
    
            
            String createTransactionTable = "CREATE TABLE IF NOT EXISTS transction ("
                    + "id INT AUTO_INCREMENT PRIMARY KEY, "
                    + "acc1 INT, "
                    + "acc2 INT, "
                    + "amount DOUBLE NOT NULL, "
                    + "status VARCHAR(20) DEFAULT 'PENDING', "
                    + "date TIMESTAMP DEFAULT CURRENT_TIMESTAMP, "
                    + "FOREIGN KEY (acc1) REFERENCES accounts(id), "
                    + "FOREIGN KEY (acc2) REFERENCES accounts(id))";
            statement.executeUpdate(createTransactionTable);
    
            String insertUsers = "INSERT INTO user (name, password) VALUES "
                    + "('Alice', 'A@123'), "
                    + "('Bob', 'B@123'), "
                    + "('Charlie', 'C@123') "
                    + "ON DUPLICATE KEY UPDATE name=name"; // Avoid duplicates
            statement.executeUpdate(insertUsers);
    
         
            String insertAccounts = "INSERT INTO accounts (id, balance, no, location) VALUES "
                    + "(1, 1000.0, 'ACC123', 'New York'), "
                    + "(2, 1500.0, 'ACC456', 'Los Angeles'), "
                    + "(3, 2000.0, 'ACC789', 'Chicago') "
                    + "ON DUPLICATE KEY UPDATE balance=balance";
            statement.executeUpdate(insertAccounts);
    
            
            String insertTransactions = "INSERT INTO transction (acc1, acc2, amount, status) VALUES "
                    + "(1, 2, 200.0, 'COMPLETED'), "
                    + "(2, 3, 300.0, 'PENDING'), "
                    + "(3, 1, 150.0, 'COMPLETED')";
            statement.executeUpdate(insertTransactions);
    
            System.out.println("Database setup completed successfully!");
    
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
    
  
    private static void showAccount(String username) {
        System.out.println("Showing account for: " + username);
    
        // Fixing SQL query: Adding single quotes around the username for proper syntax
        String query = "SELECT acc.id, acc.balance, acc.no, acc.location " +
                       "FROM accounts AS acc " +
                       "WHERE acc.id = (SELECT id FROM user WHERE name = '" + username + "')";
    
        try {
            Statement statement = get_statement(); // Assuming this function works correctly
            ResultSet rs = statement.executeQuery(query);
    
            while  (rs.next()) { // Checks if there is a result
                int accId = rs.getInt("id");
                double balance = rs.getDouble("balance");
                String accNo = rs.getString("no");
                String location = rs.getString("location");
    
                System.out.println("Account ID: " + accId);
                System.out.println("Balance: $" + balance);
                System.out.println("Account Number: " + accNo);
                System.out.println("Location: " + location);
            } 
    
            rs.close();
            statement.close();
        } catch (Exception e) {
            e.printStackTrace(); // Print the exception for debugging
        }
    }
    

    private static void showDetails(String username) {
        // Simulate account details retrieval
        System.out.println("Showing details for: " + username);
        // Add logic here to fetch and display user details
    }

    private static void showTransactions(String username) {
        // Simulate showing user transactions
        System.out.println("Showing transactions for: " + username);
        // Add logic here to fetch and display user transactions
        String  query1 =  "Select txn.acc1,txn.acc2,txn.amount,txn.status,txn.date  from transction as txn  where txn.acc1 = (select id  from user where name ="+username+")";
        try {
            Statement statement = get_statement(); // Get database statement
            String query = "SELECT txn.acc1, txn.acc2, txn.amount, txn.status, txn.date " +
                           "FROM transction AS txn " +
                           "WHERE txn.acc1 = (SELECT id FROM user WHERE name = '" + username + "')";
        
            ResultSet rs = statement.executeQuery(query);
        
            System.out.println("Showing transactions for: " + username);
            System.out.println("-------------------------------------------");
        
            while (rs.next()) {
                int acc1 = rs.getInt("acc1");
                int acc2 = rs.getInt("acc2");
                double amount = rs.getDouble("amount");
                String status = rs.getString("status");
                String date = rs.getString("date");
        
                System.out.println("From Account: " + acc1);
                System.out.println("To Account: " + acc2);
                System.out.println("Amount: $" + amount);
                System.out.println("Status: " + status);
                System.out.println("Date: " + date);
                System.out.println("-------------------------------------------");
            }
        
            rs.close();
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void goForTransaction(String username) {
        Scanner scanner = new Scanner(System.in);
    
        try {
            Statement statement = get_statement();
    
            // Step 1: Fetch User's Account ID and Balance
            String query = "SELECT id, balance FROM accounts WHERE id = (SELECT id FROM user WHERE name = '" + username + "')";
            ResultSet rs = statement.executeQuery(query);
    
            if (!rs.next()) {
                System.out.println("User account not found.");
                return;
            }
    
            int accountId = rs.getInt("id");
            double balance = rs.getDouble("balance");
    
            System.out.println("Welcome, " + username);
            System.out.println("Your current balance: $" + balance);
            System.out.println("1. Deposit");
            System.out.println("2. Withdraw");
            System.out.println("3. Transfer");
            System.out.print("Choose an option: ");
    
            int choice = scanner.nextInt();
    
            switch (choice) {
                case 1: // Deposit
                    System.out.print("Enter deposit amount: ");
                    double depositAmount = scanner.nextDouble();
                    updateBalance(accountId, balance + depositAmount);
                    logTransaction(accountId, accountId, depositAmount, "DEPOSIT");
                    System.out.println("Deposit successful. New balance: $" + (balance + depositAmount));
                    break;
    
                case 2: // Withdraw
                    System.out.print("Enter withdrawal amount: ");
                    double withdrawAmount = scanner.nextDouble();
                    if (withdrawAmount > balance) {
                        System.out.println("Insufficient balance.");
                    } else {
                        updateBalance(accountId, balance - withdrawAmount);
                        logTransaction(accountId, accountId, withdrawAmount, "WITHDRAWAL");
                        System.out.println("Withdrawal successful. New balance: $" + (balance - withdrawAmount));
                    }
                    break;
    
                case 3: // Transfer
                    System.out.print("Enter recipient account ID: ");
                    int recipientId = scanner.nextInt();
                    System.out.print("Enter transfer amount: ");
                    double transferAmount = scanner.nextDouble();
    
                    if (transferAmount > balance) {
                        System.out.println("Insufficient balance.");
                    } else {
                        updateBalance(accountId, balance - transferAmount);
                        updateBalance(recipientId, getBalance(recipientId) + transferAmount);
                        logTransaction(accountId, recipientId, transferAmount, "TRANSFER");
                        System.out.println("Transfer successful.");
                    }
                    break;
    
                default:
                    System.out.println("Invalid option.");
            }
    
            rs.close();
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
    
    // Update account balance
    private static void updateBalance(int accountId, double newBalance) throws SQLException {
        Statement statement = get_statement();
        String updateQuery = "UPDATE accounts SET balance = " + newBalance + " WHERE id = " + accountId;
        statement.executeUpdate(updateQuery);
    }
    
    // Get current balance of an account
    private static double getBalance(int accountId) throws SQLException {
        Statement statement = get_statement();
        String query = "SELECT balance FROM accounts WHERE id = " + accountId;
        ResultSet rs = statement.executeQuery(query);
        if (rs.next()) {
            return rs.getDouble("balance");
        }
        return 0.0;
    }
    
    // Log transaction in transction table
    private static void logTransaction(int senderId, int receiverId, double amount, String status) throws SQLException {
        Statement statement = get_statement();
        String insertQuery = "INSERT INTO transction (acc1, acc2, amount, status) VALUES (" 
                            + senderId + ", " + receiverId + ", " + amount + ", '" + status + "')";
        statement.executeUpdate(insertQuery);
    }
    private static boolean login(String username, String password) {
        try {
            Statement statement = get_statement();
            String query = "SELECT * FROM user WHERE name='" + username + "' AND password='" + password + "'";
            ResultSet rs = statement.executeQuery(query);
            return rs.next();
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
    }
    public static void main(String args[]) {
        setupDb();
        System.out.println("Welcomse  to  the  Banking  App");
        // String url = "jdbc:mysql://localhost:3306/bank";
        // String user = "root";
        // String password = "Java@123";
      //  Thread.currentThread().sleep(5000);
        System.out.println("Login to  the   Bank  App");
        String username="";
        String  password  = "";
        Scanner  sc  =  new  Scanner(System.in);
        System.out.print("Username : "); username=  sc.next();
        System.out.print("Password :");  password =sc.next();

        if(!login(username,password)) {
            System.out.println("Wrong Crendtails");
            main(args);
        }
        /*
         * Show  Account  
         * Show  details  
         * Show  transsction
         * GGo  for  tracnction  Acc1  //  fethc  using  thee  USername   
         */
        int choice;
        do {
            System.out.println("\n===== Account System Menu =====");
            System.out.println("1. Show Account");
            System.out.println("2. Show Details");
            System.out.println("3. Show Transactions");
            System.out.println("4. Go for Transaction (Acc1)");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();
            
            switch (choice) {
                case 1:
                    // Show Account information
                    showAccount(username);
                    break;
                case 2:
                    // Show Account details
                    showDetails(username);
                    break;
                case 3:
                    // Show transactions
                    showTransactions(username);
                    break;
                case 4:
                    // Go for transaction using the username
                    goForTransaction(username);
                    break;
                case 5:
                    System.out.println("Exiting the system...");
                    break;
                default:
                    System.out.println("Invalid choice! Please enter a valid option.");
                    break;
            }
        } while (choice != 5);
        
    }
}
/*
 * ansh@ansh-Compaq-15-Notebook-PC:~/Desktop/College assingmet/Fourth Semester/DBMS  cLG$ java -cp .:/home/ansh/Downloads/mysql-connector-j_9.2.0-1ubuntu22.04_all/usr/share/java/mysql-connector-java-9.2.0.jar Banking
Database setup completed successfully!
Welcomse  to  the  Banking  App
Login to  the   Bank  App
Username : Alice
Password :A@123

===== Account System Menu =====
1. Show Account
2. Show Details
3. Show Transactions
4. Go for Transaction (Acc1)
5. Exit
Enter your choice: 1
Showing account for: Alice
Account ID: 1
Balance: $1000.0
Account Number: ACC123
Location: New York

===== Account System Menu =====
1. Show Account
2. Show Details
3. Show Transactions
4. Go for Transaction (Acc1)
5. Exit
Enter your choice: 2
Showing details for: Alice

===== Account System Menu =====
1. Show Account
2. Show Details
3. Show Transactions
4. Go for Transaction (Acc1)
5. Exit
Enter your choice: 3
Showing transactions for: Alice
Showing transactions for: Alice
-------------------------------------------
From Account: 1
To Account: 2
Amount: $200.0
Status: COMPLETED
Date: 2025-04-01 02:38:10
-------------------------------------------

===== Account System Menu =====
1. Show Account
2. Show Details
3. Show Transactions
4. Go for Transaction (Acc1)
5. Exit
Enter your choice: 4
Welcome, Alice
Your current balance: $1000.0
1. Deposit
2. Withdraw
3. Transfer
Choose an option: 3
Enter recipient account ID: 2
Enter transfer amount: 52
Transfer successful.

===== Account System Menu =====
1. Show Account
2. Show Details
3. Show Transactions
4. Go for Transaction (Acc1)
5. Exit
Enter your choice: 4
Welcome, Alice
Your current balance: $948.0
1. Deposit
2. Withdraw
3. Transfer
Choose an option: 3
Enter recipient account ID: 3
Enter transfer amount: 500
Transfer successful.

===== Account System Menu =====
1. Show Account
2. Show Details
3. Show Transactions
4. Go for Transaction (Acc1)
5. Exit
Enter your choice: 3
Showing transactions for: Alice
Showing transactions for: Alice
-------------------------------------------
From Account: 1
To Account: 2
Amount: $200.0
Status: COMPLETED
Date: 2025-04-01 02:38:10
-------------------------------------------
From Account: 1
To Account: 2
Amount: $52.0
Status: TRANSFER
Date: 2025-04-01 02:38:45
-------------------------------------------
From Account: 1
To Account: 3
Amount: $500.0
Status: TRANSFER
Date: 2025-04-01 02:38:55
-------------------------------------------

===== Account System Menu =====
1. Show Account
2. Show Details
3. Show Transactions
4. Go for Transaction (Acc1)
5. Exit
Enter your choice: 1
Showing account for: Alice
Account ID: 1
Balance: $448.0
Account Number: ACC123
Location: New York

===== Account System Menu =====
1. Show Account
2. Show Details
3. Show Transactions
4. Go for Transaction (Acc1)
5. Exit
Enter your choice: 

 */
