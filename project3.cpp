#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Sudoku {
private:
    vector<vector<int>> grid; 
    const int SIZE = 9;       
    const int EMPTY = 0;      

    
    bool isSafe(int row, int col, int num) {
        for (int x = 0; x < SIZE; x++) {
            if (grid[row][x] == num) return false;
        }
   
        for (int x = 0; x < SIZE; x++) {
            if (grid[x][col] == num) return false;
        }
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i + startRow][j + startCol] == num) return false;
            }
        }
        return true;
    }

    
    bool solveSudoku() {
        int row, col;
        
        bool foundEmpty = false;
        for (row = 0; row < SIZE; row++) {
            for (col = 0; col < SIZE; col++) {
                if (grid[row][col] == EMPTY) {
                    foundEmpty = true;
                    break;
                }
            }
            if (foundEmpty) break;
        }
       
        if (!foundEmpty) return true;
      
        for (int num = 1; num <= 9; num++) {
            if (isSafe(row, col, num)) {
                grid[row][col] = num;
                if (solveSudoku()) return true;
                grid[row][col] = EMPTY; 
            }
        }
        return false;
    }
   
    void fillDiagonal() {
        for (int i = 0; i < SIZE; i += 3) {
            fillBox(i, i);
        }
    }
    
    void fillBox(int row, int col) {
        int num;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                do {
                    num = rand() % 9 + 1;
                } while (!isSafe(row + i, col + j, num));
                grid[row + i][col + j] = num;
            }
        }
    }
  
    void printGrid() {
        for (int i = 0; i < SIZE; i++) {
            if (i % 3 == 0 && i != 0) cout << "------+-------+------\n";
            for (int j = 0; j < SIZE; j++) {
                if (j % 3 == 0 && j != 0) cout << "| ";
                cout << (grid[i][j] == EMPTY ? "." : to_string(grid[i][j])) << " ";
            }
            cout << endl;
        }
    }

public:
    Sudoku() {
        grid.assign(SIZE, vector<int>(SIZE, EMPTY));
    }
    
    void generatePuzzle(int removeCount) {
        srand(time(0));
        fillDiagonal();
        solveSudoku();
        
        int count = removeCount;
        while (count > 0) {
            int row = rand() % SIZE;
            int col = rand() % SIZE;
            if (grid[row][col] != EMPTY) {
                grid[row][col] = EMPTY;
                count--;
            }
        }
    }

    
    void displayAndSolve() {
        cout << "Generated Sudoku Puzzle:\n";
        printGrid();

        
        vector<vector<int>> puzzle = grid;

        
        if (solveSudoku()) {
            cout << "\nSolved Sudoku:\n";
            printGrid();
        }
        else {
            cout << "\nNo solution exists.\n";
        }

        
        grid = puzzle;
    }
};

int main() {
    int n;
    Sudoku sudoku;
    cout << "How many cells should be empty? \n";
    cin >> n;
    sudoku.generatePuzzle(n); 
    sudoku.displayAndSolve();
    return 0;
}