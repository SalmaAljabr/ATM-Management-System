#include <iostream>
#include <string>
#include <ctime> // display the current time
#include <conio.h> // for _getch() function
using namespace std;

int accountNumber = 1532;
string accountHolders = "Salma Aljabr";
string accountHoldersAddress = "Al ahssa";
double accountBalance = 20000.00;  
string branch = "KSA";
double limit = 9000.00;

// Node structure for the linked list
struct BillNode {
    string name;
    int day, month, year;
    double price;
    BillNode* next;
};
BillNode* head = NULL;  // Head of the linked list

// Function to insert a bill at the beginning of the linked list
void insertNode(BillNode*& head, BillNode* newNode) {
    newNode->next = head;
    head = newNode;
}

// Function to remove a bill from a specified position in the linked list
void removeFromPosition(int position) {
    if (head == NULL) {
        cout << "Linked list is empty! Cannot remove more bills.\n";
        return;
    }

    if (position == 0) {
        BillNode* temp = head;
        head = head->next;
        delete temp;
    } else {
        BillNode* current = head;
        BillNode* previous = NULL;

        for (int i = 0; i < position && current != NULL; ++i) {
            previous = current;
            current = current->next;
        }

        if (current != NULL) {
            previous->next = current->next;
            delete current;
        } else {
            cout << "Invalid position. Cannot remove bill from position " << position << ".\n";
        }
    }
}

void details() {
    system("cls");
    cout << "\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ACCOUNT DETAILS SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n";
    cout << "\n\nThe Name of the Account Holder is: " << accountHolders << "\n\n";
    cout << "\tThe Account Holder's address is: " << accountHoldersAddress << "\n\n";
    cout << "\tThe Branch location is: " << branch << "\n\n";
    cout << "\tAccount number: " << accountNumber << "\n\n";
    cout << "\tAccount Balance: $" << accountBalance << endl;
}

void detail(){
	details();
	cout << "\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n";
	system("PAUSE");
}

void deposit() {
	system("cls");
    cout << "\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACCOUNT DEPOSIT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
    details();
    cout << "\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n";
	cout << "\tEnter the Amount to be Deposited $";
    double depositAmount;
    cin >> depositAmount;
    
    accountBalance += depositAmount;
    
    cout << "\n\tYour new available Balanced Amount is $" << accountBalance << endl;
    cout << "\n\t\t\tThank You!\n\n"<< endl;
    system("PAUSE");
}

void withdraw() {
    system("cls");
    cout << "\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACCOUNT WITHDRAWAL \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
    details();
    cout << "\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n";
    cout << "\tEnter the Amount to be Withdrawn $";
    double withdrawalAmount;
    cin >> withdrawalAmount;

    if (withdrawalAmount > accountBalance || withdrawalAmount > limit) {
        cout << endl << "\tPlease Try Again, the withdrawal amount exceeds your available balance or limit!\n" << endl;
        system("PAUSE");
    } else {
        accountBalance -= withdrawalAmount;
        cout << "\n\tYou have successfully Withdrawn: $" << withdrawalAmount << "\n";
        cout << "\n\tYour new Balance Amount is $" << accountBalance << endl;
        cout << "\n\t\t\tThank You!\n\n" << endl;
        system("PAUSE");
    }
}

// Function to arrange bills based on due date using bubble sort
void arrangeBillsByDate() {
    // Bubble sort to arrange bills based on due date
    for (BillNode* i = head; i != NULL; i = i->next) {
        for (BillNode* j = head; j->next != NULL; j = j->next) {
            // Compare due dates
            if (j->year > j->next->year ||
                (j->year == j->next->year && j->month > j->next->month) ||
                (j->year == j->next->year && j->month == j->next->month && j->day > j->next->day)) {
                // Swap the bills if they are out of order
                swap(j->name, j->next->name);
                swap(j->day, j->next->day);
                swap(j->month, j->next->month);
                swap(j->year, j->next->year);
                swap(j->price, j->next->price);
            }
        }
    }
}

void AddBills() {
    system("cls");

    int numberOfBills;
    cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Enter the number of bills: \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb" << endl;
    cin >> numberOfBills;

    // Iterate through each bill
    for (int i = 0; i < numberOfBills; ++i) {
        BillNode* newNode = new BillNode;
        cin.ignore();  // Consume the newline character left in the input buffer

        // Get bill details from the user u
        cout << "Enter bill name: ";
        getline(cin, newNode->name); 

        cout << "Enter day, month, and year (separated by spaces): ";
        cin >> newNode->day >> newNode->month >> newNode->year;

        cout << "Enter the price for the bill: $";
        cin >> newNode->price;

        // Insert the current bill at the beginning of the linked list
        insertNode(head, newNode);
    }
    // Arrange the bills based on due date
    arrangeBillsByDate();
    system("PAUSE");
}

// Function to count the number of bills in the linked list
int countBills() {
    int count = 0;
    BillNode* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void displayArrangedBills() {
    BillNode* current = head;

    cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Arranged bills based on due date: \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb" << endl;

    while (current != NULL) {
        cout << "Bill Name: " << current->name
             << " (Date: " << current->day << "/" << current->month << "/" << current->year
             << ", Price: $" << current->price << ")" << endl;
        current = current->next;
    }
}

// Function to handle the payment of bills
void payBills() {
    // Clear the console screen for a clean display
    system("cls");

    // Check if there are bills to pay
    if (head == NULL) {
        cout << "No bills to pay. Add bills first.\n";
        system("PAUSE");
        return;
    }

    // Display the list of arranged bills with due dates and amounts
    displayArrangedBills();

    // Ask the user to select a bill to pay
    cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Enter the number of the bill to pay (1-" << countBills() << "): \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb" << endl;
    int billNumber;
    cin >> billNumber;
    
    // Validate the user input for the selected bill number
    if (billNumber < 1 || billNumber > countBills()) {
        cout << "Invalid bill number. Please try again.\n";
        system("PAUSE");
        return;
    }

    // Get the amount of the selected bill
    double billAmount;
    BillNode* current = head;
    for (int i = 1; i < billNumber; ++i) {
        current = current->next;
    }
    billAmount = current->price;

    // Check if the user has sufficient funds to pay the bill
    if (billAmount > accountBalance) {
        cout << "Insufficient funds to pay the bill.\n";
        system("PAUSE");
        return;
    }

    // Deduct the bill amount from the account balance
    accountBalance -= billAmount;

    // Remove the paid bill from the linked list
    removeFromPosition(billNumber - 1);
    
    /// Display a success message with the updated account balance
    cout << "Bill paid successfully. Your new balance is $" << accountBalance << endl;

    // Pause the system to allow the user to read the message before returning to the main menu
    system("PAUSE");
}


void accountExit() {
    system("cls");
    cout << "\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB    2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
    cout << "\n\t\tThank you for using the ATM. Have a great day!\n\n";
    system("PAUSE");
}

int getHiddenInput() {
    int input = 0;
    char ch;
    
    // Read characters until Enter is pressed
    while ((ch = _getch()) != 13) { // 13 is the ASCII code for Enter
        // Check if the input is a digit
        if (isdigit(ch)) {
            cout << '*'; // Print '*' instead of the actual character
            input = input * 10 + (ch - '0'); // Convert char to int
        }
    }

    cout << endl; // Move to the next line after Enter is pressed
    return input;
}

string isUserRobot() {
    cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Are you a robot? (yes/no): \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb "<< endl;
    string answer;
    cin >> answer;

    // Convert each character in the answer to lowercase for case-insensitive comparison
    for (size_t i = 0; i < answer.size(); ++i) {
        answer[i] = tolower(answer[i]);
    }

    return answer;
}


int main() {

    int choice;

    while (true) {
        system("cls");
	    cout<<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACCOUNT DETAILS \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
        cout << "\t\t\t--------------------\n" << endl;
        cout << "\t\tCurrent date : ";
        time_t now;
        time(&now);
        printf("%s\n", ctime(&now));;
        cout << "\t\t\t--------------------\n" << endl;
        cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
        cout << "\tPress 1 and Then Press Enter to Access Your Account Via Pin Number\n\n";
        cout << "\t\t\t\t\t or \n\n";
        cout << "\tPress 0 and press Enter to get Help.\n\n";

        int access;
        cin >> access;

        switch (access) {
            case 1:
                system("cls");
                int i, pin;
                
                if (isUserRobot() == "yes" ) {
                    cout << "Sorry, only humans are allowed to access this account." << endl;
                    system("PAUSE");
                    exit(1);
                }
                system("cls");
                cout << "\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ATM ACCOUNT ACCESS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
                cout << "\n\nEnter Your Acc Pin Access Number! [Only one attempt is allowed]\n\n" << endl;
                cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
                pin = getHiddenInput();

                system("cls");

                if (pin == 12345) {
                    system("cls");
                    do {
                        system("cls");
                        cout << endl << "\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM Main Menu Screen \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n" << endl << endl;
                        cout << "\tPLEASE ENTER A SELECTION AND PRESS RETURN KEY: \n\n";
						cout << "\t\tEnter [1] To Deposit Cash" << endl;
                        cout << "\t\tEnter [2] To Withdraw Cash" << endl;
                        cout << "\t\tEnter [3] To Balance Inquiry" << endl;
                        cout << "\t\tEnter [4] Add new bills" << endl;
                        cout << "\t\tEnter [5] Pay bills" << endl;
                        cout << "\t\tEnter [0] to Exit ATM" << endl << endl;
                        
                        cin >> choice;

                        switch (choice) {
                            case 0:
                                system("cls");
                                cout << "\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACCOUNT STATUS \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
                                cout << "\t See your bank representative for assistance during bank opening hours\n\n";
                                cout << "\t\tThank you for choosing our services today!!\n\n";
                                cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
                                system("PAUSE");
                                exit(0);
                                break;
                            case 1:
                                deposit();
                                break;
                            case 2:
                                withdraw();
                                break;
                            case 3:
                                detail();
                                break;
                            case 4:
                                AddBills();
                                displayArrangedBills();
                                break;
                            case 5:
                                payBills();
                                break;
                            default:
                                cout << "\nInvalid choice. Please try again.\n";
                                break;
                        } 
                    } while (choice != 0);
                } else {
                    system("cls");
                    cout << "\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb THANK YOU \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
                    cout << "\nYou had made your attempt which failed!!! No More attempts allowed!! Sorry!!\n\n";
                    cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
					system("PAUSE");
                    exit(1);
                }
                break;
            case 0:
                system("cls");
                cout << "\n\n\n\t\t\t\t     ATM HELP AND CUSTOMER SUPPORT\n\n\n";
                cout << "The ATM is a computerized device which provides various facilities to its account holders, such as:\n\n";
                cout << "\t- Cash withdrawals\n";
                cout << "\t- Balance inquiry\n";
                cout << "\t- Cash deposit\n";
                cout << "\t- Bill payments\n";
                cout << "\t- Account management\n";
                cout << "\t- And more...\n\n";
                cout << "For assistance or to report a problem, please contact our customer\n";
                cout << "support at 1-800-123-4567.\n\n";
                system("PAUSE");
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    return 0;
}
