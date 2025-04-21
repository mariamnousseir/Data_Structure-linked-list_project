#include <iostream>
#include <limits>             //include the limits library to use numeric_limits for buffer clearing
#include "tokenizer.h"        //include the custom tokenizer header for splitting expressions into tokens
#include "converter.h"        //include the custom converter header for notation conversion functions

using namespace std;

//function to print all tokens in a TokenList, separated by spaces
void printList(TokenList* list) {
    for (TokenNode* cur = list->head; cur; cur = cur->next)    //iterate through each node in the list
        cout << cur->token << ' ';                            //print the current token followed by a space
    cout << endl;                                             //print a newline after all tokens are printed
}

int main() {
    while (true) {                                            //loop indefinitely until the user chooses to exit
        cout << "Choose notation (1: Infix, 2: Postfix, 3: Prefix, 4: Exit): ";  //prompt user for choice
        int choice;                                           //variable to store the user's menu choice
        if (!(cin >> choice)) break;                         //if reading fails, exit the loop
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear the input buffer up to the next newline

        if (choice == 4) break;                              //if the user chose 4, exit the loop and program

        cout << "Enter expression: ";                        //prompt user to enter an expression
        string expr;                                         //string to hold the user's expression
        getline(cin, expr);                                  // Read the full line of input into expr

        TokenList* r1 = nullptr;                             //pointer for the first result list initialized to null
        TokenList* r2 = nullptr;                             //pointer for the second result list initialized to null

        try {                                                 //begin a try block to catch any conversion errors
            if (choice == 1) {                               //if user selects Infix
                TokenList* t1 = tokenize(expr);             //tokenize expression for postfix conversion
                TokenList* t2 = tokenize(expr);             //tokenize expression again for prefix conversion
                r1 = infixToPostfix(t1);                     //convert infix tokens to postfix
                r2 = infixToPrefix(t2);                      //convert infix tokens to prefix
                delete t1; delete t2;                        //free memory allocated for the temporary token lists
                cout << "Postfix: ";  printList(r1);         //print the postfix result
                cout << "Prefix:  ";  printList(r2);         //print the prefix result
            }
            else if (choice == 2) {                          //if user selects Postfix
                TokenList* t1 = tokenize(expr);             //tokenize for infix conversion
                TokenList* t2 = tokenize(expr);             //tokenize for prefix conversion
                r1 = postfixToInfix(t1);                     //convert postfix tokens to infix
                r2 = postfixToPrefix(t2);                    //convert postfix tokens to prefix
                delete t1; delete t2;                        //clean up temporary token lists
                cout << "Infix:   ";  printList(r1);         //print the infix result
                cout << "Prefix:  ";  printList(r2);         //print the prefix result
            }
            else if (choice == 3) {                          //if user selects Prefix
                TokenList* t1 = tokenize(expr);             //tokenize for infix conversion
                TokenList* t2 = tokenize(expr);             //tokenize for postfix conversion
                r1 = prefixToInfix(t1);                     //convert prefix tokens to infix
                r2 = prefixToPostfix(t2);                   //convert prefix tokens to postfix
                delete t1; delete t2;                        //free temporary token lists
                cout << "Infix:   ";  printList(r1);         //print the infix result
                cout << "Postfix: ";  printList(r2);         //print the postfix result
            }
            else {                                          //if the user enters an invalid choice
                cout << "Invalid choice.\n";                //inform the user of the invalid selection
            }
        }
        catch (const exception& e) {                        //catch any exceptions thrown during conversion
            cout << "Error: " << e.what() << endl;          //print the error message to the console
        }

        delete r1;                                          //free memory for the first result list (if allocated)
        delete r2;                                          //free memory for the second result list (if allocated)
    }
    cout << "You exit the program. Thank you!\n";
    return 0;
}
