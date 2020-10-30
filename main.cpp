#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "Solver.hpp"
using namespace std;

void interface();
int menu1();
int menu2();
int menu3();
void help();

void solve();

int main() {
    interface();

    system("pause");
    return 0;
}

void interface(){
    int choice = 0;
    cout << "Welcome to the Supreme Sudoku Solver! by Jackson Raffety" << endl;

    while(choice != 3){
        choice = menu1();

        //solve puzzle
        if(choice == 1){
            solve();
        //help
        }else if(choice == 2){
            help();
        }
    }
    cout << "\nGOODBYE" << endl;
}

int menu1(){
    int choice = 1;
    do{
        if(choice != 1){
            cout << endl << "INVALID OPTION" << endl << endl;
        }
        cout << "\nMenu:" << endl;
        cout << "\t1. Solve Puzzle\n\t2. Help\n\t3. Exit" << endl;
        cout << "> ";
        cin >> choice;
    } while(choice != 1 && choice != 2 && choice != 3);
    return choice;
}

int menu2(){
    int choice = 1;
    do{
        if(choice != 1){
            cout << endl << "INVALID OPTION" << endl << endl;
        }
        cout << "What method do you wish to input your puzzle?" << endl;
        cout << "\t1. Console\n\t2. File" << endl;
        cout << "> ";
        cin >> choice;
    } while(choice != 1 && choice != 2);
    return choice;
}

int menu3(){
    int choice = 1;
    do{
        if(choice != 1){
            cout << endl << "INVALID OPTION" << endl << endl;
        }
        cout << "What method do you wish to output your puzzle?" << endl;
        cout << "\t1. Console\n\t2. File" << endl;
        cout << "> ";
        cin >> choice;
    } while(choice != 1 && choice != 2);
    return choice;
}

void solve(){
    Solver puzzle;
    int choice1, choice2;
    ifstream input;
    string output = "solution.txt";
    string fileName;

    cout << endl;
    choice1 = menu2();

    cout << endl;
    choice2 = menu3();

    if(choice1 == 1){
        cout << endl << "Please enter in your puzzle here: " << endl;
        puzzle.readPuzzle(cin);
    } else{
        do{
            cout << endl << "Please enter the name/path of your file here (enter 0 to exit): " << endl;
            cin >> fileName;
            input.clear();

            if(fileName == "0"){
                exit(1);
            }

            input.open(fileName.c_str());

            if(!input){
                cout << endl << "ERROR: COULD NOT OPEN FILE" << endl;
            }

        } while(!input);
        puzzle.readPuzzle(input);
    }

    puzzle.solve();

    if(choice2 == 1){
        cout << endl << endl;
        puzzle.printPuzzle(cout);
    } else{
        cout << "Your output is now put into a file." << endl;
        ofstream file(output.c_str());
        puzzle.printPuzzle(file);
    }

}

void help(){
    cout << "\n\n\n\n";
    cout << "This program takes in a sudoku puzzle and returns the";
    cout << "\nsolution to it. The sudoku puzzles should be input\n";
    cout << "the following format:" << endl << endl;
    cout << "0 7 5 0 9 0 0 0 6\n0 2 3 0 8 0 0 4 0\n8 0 0 0 0 3 0 0 1\n";
    cout << "5 0 0 7 0 2 0 0 0\n0 4 0 8 0 6 0 2 0\n0 0 0 9 0 1 0 0 3\n";
    cout << "9 0 0 4 0 0 0 0 7\n0 6 0 0 7 0 5 8 0\n7 0 0 0 1 0 3 9 0\n";
    cout << endl << "Where the 0s represent empty spaces. And the numbers\n";
    cout << "to solid spaces. Please use spaces to separate the values." << endl;
    cout << endl << "You have the possibility to input puzzles from text files." << endl;
    cout << "As long as the files are in the above format, then it will work." << endl;
    cout << "If the file is not in the same folder as the executable, then you will need to enter the full path" << endl;
    cout << "You can also output the solutions to the puzzles to a file if you like. It will be" << endl;
    cout << "placed into the same folder as the executable and named \"solution.txt\"." << endl;
    cout << "If you wish to solve multiple solutions in a single run, note that it is not" << endl;
    cout << "currently possible to output to more than 1 file without deleting the prior one(s)." << endl;
    cout << endl << endl;
}