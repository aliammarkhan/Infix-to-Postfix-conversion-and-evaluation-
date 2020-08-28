# Infix-to-Postfix-conversion-and-evaluation-
Converting an infix expression to postfix and evaluating it

## About the problem

Arithmetic expressions are made of operators (+, -, /, *, ^, etc.) and operands (either numbers,
variables or, recursively, smaller arithmetic expressions). The expressions can be written in a
variety of notations. In this problem, you will focus on two standard arithmetic expression
notations: infix and postfix. In Infix expression, operators are written in-between their operands.
This is the usual way we write expressions, for example x+y. Similarly, Postfix notation (also
known as "Reverse Polish notation"): x y + Operators are written after their operands. There is a
general algorithm that convert an infix expression to postfix using stack (data structure). The
algorithm is given below:

## Algorithm (Converting an Infix expression to Postfix expression

1) Examine the next element in the input.
2) If it is an operand, output it.
3) If it is opening parenthesis, push it on stack.
4) If it is an operator, then
i) If stack is empty, push operator on stack.
ii) If the top of the stack is opening parenthesis, push operator on stack.
iii) If it has higher priority than the top of stack, push operator on stack. (operator
priorities ^, *, /, +, and -.
iv) Else pop the operator from the stack and output it, repeat step 4.
5) If it is a closing parenthesis, pop operators from the stack and output them until an
opening parenthesis is encountered. pop and discard the opening parenthesis.
6) If there is more input go to step 1
7) If there is no more input, unstack the remaining operators to output. 

Input/Output: The input file will contain one valid expression in infix form. The output file must
contain the valid postfix version of that expression and in the next line it must have its evaluated
result. 

