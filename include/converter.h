#ifndef CONVERTER_H                    //include guard start: prevents multiple inclusions of this header
#define CONVERTER_H

#include <string>
#include "stack.h"                    //include custom Stack template for stack operations
#include "tokenizer.h"                //include TokenList and tokenize() for token handling

using namespace std;

//return operator precedence: higher number means higher precedence
inline int precedence(const string& op) {
    if (op == "^")               return 3;  //exponentiation has highest precedence
    if (op == "*" || op == "/")  return 2;  //multiplication and division next
    if (op == "+" || op == "-")  return 1;  //addition and subtraction lowest
    return 0;                             //nonoperators have precedence 0
}

//check if a token is one of the arithmetic operators
inline bool isOperator(const string& t) {
    return t == "+" || t == "-" || t == "*" || t == "/" || t == "^";
}
//**************************************************************************************************//
//convert an infix token list to postfix notation
inline TokenList* infixToPostfix(TokenList* tokens) {
    TokenList* output = new TokenList();  //output list for postfix tokens
    Stack<string> st;                     //operator stack
    while (!tokens->isEmpty()) {          //process tokens until input is exhausted
        string t = tokens->popFront();    //get next token
        if (!isOperator(t) && t != "(" && t != ")") {
            output->append(t);            //if it's an operand, append to output
        }
        else if (t == "(") {
            st.push(t);                   //if it's '(', push onto stack
        }
        else if (t == ")") {
            //pop until matching '('
            while (!st.isEmpty() && st.peek() != "(")
                output->append(st.pop());
            if (!st.isEmpty()) st.pop();  //remove the '(' from stack
        }
        else {
            //operator: pop higher-or-equal precedence operators first (left-associative except '^')
            while (!st.isEmpty() && isOperator(st.peek()) &&
                (precedence(st.peek()) > precedence(t) ||
                    (precedence(st.peek()) == precedence(t) && t != "^")))
                output->append(st.pop());
            st.push(t);                   //push current operator
        }
    }
    //append any remaining operators
    while (!st.isEmpty())
        output->append(st.pop());
    return output;                        //return the postfix token list
}

//*************************************************************************************************//
// Convert infix to prefix by reversing, converting to postfix, then reversing again
inline TokenList* infixToPrefix(TokenList* tokens) {
    tokens->reverse();                    //reverse token order
    // Swap parentheses
    for (TokenNode* cur = tokens->head; cur; cur = cur->next) {
        if (cur->token == "(") cur->token = ")";
        else if (cur->token == ")") cur->token = "(";
    }
    TokenList* post = infixToPostfix(tokens);  //convert modified list to postfix
    post->reverse();                       //reverse result to get prefix
    return post;                           //return prefix token list
}

//***************************************************************************************************//
//convert postfix to infix notation
inline TokenList* postfixToInfix(TokenList* tokens) {
    Stack<string> st;                      //stack to hold intermediate expressions
    while (!tokens->isEmpty()) {
        string t = tokens->popFront();
        if (!isOperator(t))
            st.push(t);                    //operand: push onto stack
        else {
            //operator: pop two operands, combine into "(a op b)"
            string b = st.pop();
            string a = st.pop();
            st.push("(" + a + " " + t + " " + b + ")");
        }
    }
    return tokenize(st.pop());             //tokenize and return the final expression
}
//*******************************************************************************************************//
























#endif // CONVERTER_H