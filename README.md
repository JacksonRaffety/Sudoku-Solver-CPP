# Sudoku-Solver-CPP
A simple C++ program that takes an unfinished Sudoku puzzle and finds a solution to the puzzle. Made one day while bored at the airport.

Program provides simple command line user interface, with options to input/output puzzles/solutions through both the console and through files. The command line interface also
provides a help menu, describing the format of the input and output the solver uses.

Currently, no arguments are accepted by the program to bypass te user interface. They may be added in the future, however.

## Algorithm
The algorithm used to solve Sudoku puzzles is a simple backtracing one. Going in order, from left -> right, top -> bottom, increment an empty square and check the state of the board. If there is no logic error, continue to the next empty square and increment it. Once a logical error is reached, increment the current square again, until it overlows past 9 back to 0. Then, backtrace to the previously incremented empty square, and increment that one agian. Repeat the process untill all empty squares are filled with no logical error.

This algorithm allows for the detection of impossible setups, and is detected when the first empty square overflows. Due to the nature of this algorithm, if the puzzle has a solution, a sollution will be found, no false positives or false negatives. However, if a puzzle is deterministic (that is to say, can have multiple solutions), the algorithm will simply output the first solution it can make, and won't detect other solutions, or even if its possible that other solutions exist. 
