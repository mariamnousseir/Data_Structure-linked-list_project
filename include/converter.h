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
// Convert postfix to prefix notation
inline TokenList* postfixToPrefix(TokenList* tokens) {
    Stack<string> st;                      // Stack for building prefix strings
    while (!tokens->isEmpty()) {
        string t = tokens->popFront();
        if (!isOperator(t))
            st.push(t);                    // Operand: push
        else {
            // Operator: pop b then a, form "op a b"
            string b = st.pop();
            string a = st.pop();
            st.push(t + " " + a + " " + b);
        }
    }
    return tokenize(st.pop());             // Tokenize the prefix string
}
//*******************************************************************************************************//
// Convert prefix to infix by reversing tokens and using a stack
inline TokenList* prefixToInfix(TokenList* tokens) {
  tokens->reverse();  //reverse token order to process prefix expressions from right to left, also because stacks are LIFO structure
  Stack<string> st;   //stack for building infix strings called st
  //loop through tokens in reversed order and check if token is an operator or operand
  while (!tokens->isEmpty()) {
    string t = tokens->popFront();
    if (!isOperator(t)) //if token is not an operator(A,B,1) , push into the stack
      st.push(t);   //operand: push
    else { //token is an operator(+,-,*,/)
      //operator: pop a then b, "(a operator b)"
      //pop two operands from stack and combine the operands with the operator
      string a = st.pop();
      string b = st.pop();
      st.push("(" + a + " " + t + " " + b + ")"); //push back combined expression onto the stack
    }
  }
  return tokenize(st.pop());   //tokenize the infix string(split into tokens) and return token list
}
//*******************************************************************************************************//
//Convert prefix to postfix by similar reverse-and-stack method
inline TokenList* prefixToPostfix(TokenList* tokens) {
  tokens->reverse(); //reversing tokens first
  Stack<string> st;  //stack for building postfix strings
  while (!tokens->isEmpty()) {
    string t = tokens->popFront();
    if (!isOperator(t)) //check if token is not an operator (A,B,1) , push into the stack
      st.push(t);  //operand: push
    else { //in case token is an operator
      //operator: pop a then b, ("a b operator")
      //pop 2 operands from the stack
      string a = st.pop(); //popping first operand (on top of the stack)
      string b = st.pop(); //popping second operand
      st.push(a+""+b+""+t); //combining in postfix order (A, B, operator)
    }
  }
  return tokenize(st.pop()); //the final result is on top of the stack so, tokenize and return
}
//*******************************************************************************************************//
#endif // CONVERTER_H
