# Prefix to Postfix

## Problem Statement
Given an prefix expression, convert it to a postfix expression. The prefix expression will consist of single-letter variables (a-z), operators (^, *, /, +, -), and parantheses. The priority of the operators is as follows:
1. `^` (highest)
2. `*` and `/`
3. `+` and `-`
4. Anything else (lowest)

## Solution Approach
To convert an prefix expression to a postfix expression, we can use a stack-based approach. The algorithm can be summarized as follows:
1. Initialize an empty stack.
2. Iterate through each character in the prefix expression (right to left):
   - If the character is an operand (a-z), push it onto the stack.
   - If the character is an operator, pop two operands from the stack, create a new postfix expression by placing the operator after them, and push the resulting expression back onto the stack.
3. After iterating through the prefix expression, the stack will contain a single element, which is the converted postfix expression.