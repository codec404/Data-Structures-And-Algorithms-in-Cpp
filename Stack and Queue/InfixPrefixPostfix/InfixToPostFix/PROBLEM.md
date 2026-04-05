# Infix To Postfix

## Problem Statement
Given an infix expression, convert it to a postfix expression. The infix expression will consist of single-letter variables (a-z), operators (^, *, /, +, -), and parantheses. The priority of the operators is as follows:
1. `^` (highest)
2. `*` and `/`
3. `+` and `-`
4. Anything else (lowest)

## Solution Approach
To convert an infix expression to a postfix expression, we can use a stack data structure to hold operators and ensure that they are output in the correct order based on their precedence. The algorithm can be summarized as follows:
1. Initialize an empty stack for operators and an empty string for the output.
2. Iterate through each character in the infix expression:
   - If the character is an operand (a-z), append it to the output string.
   - If the character is an operator, pop operators from the stack to the output string until the stack is empty or the operator at the top of the stack has lower (<=)precedence than the current operator. Then push the current operator onto the stack.
   - If the character is an opening parenthesis '(', push it onto the stack.
   - If the character is a closing parenthesis ')', pop operators from the stack to the output string until an opening parenthesis '(' is encountered on the stack. Pop the '(' from the stack but do not add it to the output string.
3. After iterating through the infix expression, pop any remaining operators from the stack to the output string.