//
// Created by Jackson on 3/2/2018.
//

#include "Solver.hpp"

Solver::Solver(){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            puzzle[i][j] = 0;
            solids[i][j] = 0;
        }
    }
}
Solver::Solver(istream& in){
    readPuzzle(in);
}

void Solver::readPuzzle(istream& in){
    int val;
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            in >> val;
            puzzle[i][j] = val;
            solids[i][j] = val;
        }
    }
}
bool Solver::checkRows(){
    bool checked = true;
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL-1; j++){
            for(int k = j+1; k < COL; k++){
                if(puzzle[i][j] == puzzle[i][k] && puzzle[i][j] != 0){
                    checked = false;
                }
            }
        }
    }
    return checked;
}
bool Solver::checkColumns(){
    bool checked = true;
    for(int j = 0; j < COL; j++){
        for(int i = 0; i < ROW-1; i++){
            for(int k = i+1; k < ROW; k++){
                if(puzzle[i][j] == puzzle[k][j] && puzzle[i][j] != 0){
                    checked = false;
                }
            }
        }
    }
    return checked;
}
bool Solver::checkGrids(){
    bool checked = true;
    int *temp = new int[GRID*GRID];
    int count = 0;
    for(int rg = 0; rg < GRID; rg++){
        for(int cg = 0; cg < GRID; cg++){
            count = 0;
            for(int i = rg*GRID; i < rg*GRID+GRID; i++){
                for(int j = cg*GRID; j < cg*GRID+GRID; j++){
                    temp[count] = puzzle[i][j];
                    count++;
                }
            }
            checked = checkGrid(temp);
            if(!checked){
                delete [] temp;
                return checked;
            }
        }
    }
    return checked;
}

void Solver::printPuzzle(ostream& out){
    out << "SOLUTION: " << endl;
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            out << puzzle[i][j] << " ";
        }
        out << endl;
    }
}

bool Solver::checkGrid(int* temp){
    bool checked = true;
    for(int i = 0 ; i < GRID*GRID-1; i++){
        for(int k = i+1; k < GRID*GRID; k++){
            if(temp[i] == temp[k] && temp[i] != 0){
                checked = false;
            }
        }
    }
    return checked;
}

bool Solver::masterCheck(){
    bool checked = true;
    if(!checkColumns() || !checkRows() || !checkGrids()){
        checked = false;
    }
    return checked;
}

void Solver::solve(){
    int row = 0, col = 0;

    bool solved = false;

    while(!solved){
        /*
        printPuzzle();
        cout << endl;
*/
        //check if solid
        if(solids[row][col] != 0){
            incrementRC(row,col);
            continue;
        }

        bumpValue(row,col);

        while(!masterCheck()){
            bumpValue(row,col);
        }

        //check
        if(row == ROW-1 && col == COL-1 && masterCheck()){
            solved = true;
        }
        incrementRC(row,col);
    }
}


void Solver::bumpValue(int& row, int& col){
    if(puzzle[row][col] == 9){
        do{
            puzzle[row][col] = 0;
            decrementRC(row,col);

        } while(puzzle[row][col] == 9 && solids[row][col] == 0);
    }
    puzzle[row][col]++;
}

void Solver::incrementRC(int& row, int& col){
    if(col == COL-1){
        col = 0;
        row++;
    } else{
        col++;
    }
}


void Solver::decrementRC(int& row, int& col){
    do{
        if(col == 0){
            col = COL-1;
            row--;
        } else{
            col--;
        }
    } while(solids[row][col] != 0);
}


bool Solver::preCheck(){
    bool checked = true;
    if(!preCheckColumns() || !preCheckRows() || !preCheckGrids()){
        checked = false;
    }
    return checked;
}

bool Solver::preCheckRows(){
    bool checked = true;
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL-1; j++){
            for(int k = j+1; k < COL; k++){
                if(solids[i][j] == solids[i][k] && solids[i][j] != 0){
                    checked = false;
                }
            }
        }
    }
    return checked;
}
bool Solver::preCheckColumns(){
    bool checked = true;
    for(int j = 0; j < COL; j++){
        for(int i = 0; i < ROW-1; i++){
            for(int k = i+1; k < ROW; k++){
                if(solids[i][j] == solids[k][j] && solids[i][j] != 0){
                    checked = false;
                }
            }
        }
    }
    return checked;
}
bool Solver::preCheckGrids(){
    bool checked = true;
    int *temp = new int[GRID*GRID];
    int count = 0;
    for(int rg = 0; rg < GRID; rg++){
        for(int cg = 0; cg < GRID; cg++){
            count = 0;
            for(int i = rg*GRID; i < rg*GRID+GRID; i++){
                for(int j = cg*GRID; j < cg*GRID+GRID; j++){
                    temp[count] = solids[i][j];
                    count++;
                }
            }
            checked = checkGrid(temp);
            if(!checked){
                delete [] temp;
                return checked;
            }
        }
    }
    return checked;
}