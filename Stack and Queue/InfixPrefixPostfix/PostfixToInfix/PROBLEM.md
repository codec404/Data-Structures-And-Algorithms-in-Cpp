# Postfix to Infix

## Problem Statement
Given an postfix expression, convert it to a infix expression. The postfix expression will consist of single-letter variables (a-z), operators (^, *, /, +, -), and parantheses. The priority of the operators is as follows:
1. `^` (highest)
2. `*` and `/`
3. `+` and `-`
4. Anything else (lowest)

## Solution Approach
To convert an postfix expression to a infix expression, we can use a stack-based approach. The algorithm can be summarized as follows:
1. Initialize an empty stack.
2. Iterate through each character in the postfix expression:
   - If the character is an operand (a-z), push it onto the stack.
   - If the character is an operator, pop two operands from the stack, create a new infix expression by placing the operator between them, and push the resulting expression back onto the stack.
3. After iterating through the postfix expression, the stack will contain a single element, which is the converted infix expression.