//
// Created by Jackson on 3/2/2018.
//

#ifndef SUDOKU_SOLVER_SOLVER_HPP
#define SUDOKU_SOLVER_SOLVER_HPP

#include <iostream>
using namespace std;

const int ROW = 9;
const int COL = 9;
const int GRID = 3;



class Solver {
private:
    int puzzle[ROW][COL];
    int solids[ROW][COL];
public:
    Solver();
    Solver(istream& in);

    void readPuzzle(istream& in);

    void solve();

    void bumpValue(int& row, int& col);
    void incrementRC(int& row, int& col);
    void decrementRC(int& row, int& col);

    bool masterCheck();
    bool checkRows();
    bool checkColumns();
    bool checkGrids();
    bool checkGrid(int* temp);

    bool preCheck();
    bool preCheckRows();
    bool preCheckColumns();
    bool preCheckGrids();

    void printPuzzle(ostream& out);
};

#endif //SUDOKU_SOLVER_SOLVER_HPP
