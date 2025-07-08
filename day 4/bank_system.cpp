#include <iostream>
#include <string>
#include <vector>
#include <limits> // For input validation

using namespace std;

// Transaction structure for history tracking
struct Transaction {
    string type;
    double amount;
    string timestamp;
};

// Global variables (simplified for this project)
double balance = 0.0;
vector<Transaction> transactionHistory;
const string PASSWORD = "bank123"; // Admin password

// ===== CORE FUNCTIONS =====
void showBalance() {
    cout << "\n💰 Current Balance: $" << balance << endl;
}

double deposit() {
    double amount;
    cout << "Enter deposit amount: $";
    if(!(cin >> amount) || amount <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "❌ Invalid amount!" << endl;
        return balance;
    }
    
    balance += amount;
    
    // Record transaction
    transactionHistory.push_back({"DEPOSIT", amount, "NOW"});
    
    cout << "✅ $" << amount << " deposited successfully!";
    showBalance();
    return balance;
}

double withdraw() {
    double amount;
    cout << "Enter withdrawal amount: $";
    if(!(cin >> amount) || amount <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "❌ Invalid amount!" << endl;
        return balance;
    }
    
    if(amount > balance) {
        cout << "❌ Insufficient funds!" << endl;
        return balance;
    }
    
    balance -= amount;
    
    // Record transaction
    transactionHistory.push_back({"WITHDRAWAL", amount, "NOW"});
    
    cout << "✅ $" << amount << " withdrawn successfully!";
    showBalance();
    return balance;
}

void printReceipt(const string &txn_type, double amount) {
    cout << "\n================ RECEIPT ================";
    cout << "\n  Transaction: " << txn_type;
    cout << "\n  Amount: $" << amount;
    cout << "\n  New Balance: $" << balance;
    cout << "\n  Date: SYSTEM_TIME"; // Implement time later
    cout << "\n========================================" << endl;
}

void showHistory() {
    if(transactionHistory.empty()) {
        cout << "\nNo transactions yet!" << endl;
        return;
    }
    
    cout << "\n🕒 TRANSACTION HISTORY:\n";
    for(const auto& txn : transactionHistory) {
        cout << "• " << txn.type << ": $" << txn.amount 
             << " at " << txn.timestamp << endl;
    }
}

bool adminLogin() {
    string input;
    cout << "\nEnter admin password: ";
    cin >> input;
    return (input == PASSWORD);
}

// ===== MAIN DRIVER =====
int main() {
    int choice;
    bool running = true;
    
    cout << "🏦 WELCOME TO CLI BANKING SYSTEM\n";
    
    while(running) {
        cout << "\n================ MENU ================";
        cout << "\n1. Show Balance";
        cout << "\n2. Deposit Money";
        cout << "\n3. Withdraw Money";
        cout << "\n4. View Transaction History";
        cout << "\n5. Admin Mode";
        cout << "\n6. Exit";
        cout << "\n======================================";
        cout << "\nEnter choice (1-6): ";
        
        if(!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "❌ Invalid input! Please enter a number." << endl;
            continue;
        }

        switch(choice) {
            case 1:
                showBalance();
                break;
            case 2: {
                double old_balance = balance;
                deposit();
                if(balance > old_balance) {
                    printReceipt("DEPOSIT", balance - old_balance);
                }
                break;
            }
            case 3: {
                double old_balance = balance;
                withdraw();
                if(balance < old_balance) {
                    printReceipt("WITHDRAWAL", old_balance - balance);
                }
                break;
            }
            case 4:
                showHistory();
                break;
            case 5:
                if(adminLogin()) {
                    cout << "\n🔓 ADMIN MODE ACTIVATED";
                    cout << "\nTransactions: " << transactionHistory.size();
                    cout << "\nSystem security: ACTIVE\n";
                } else {
                    cout << "❌ Access denied!" << endl;
                }
                break;
            case 6:
                cout << "👋 Thank you for banking with us!" << endl;
                running = false;
                break;
            default:
                cout << "⚠️ Invalid choice! Try again." << endl;
        }
    }
    return 0;
}
