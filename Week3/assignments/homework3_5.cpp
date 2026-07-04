#include <iostream>
#include <vector>
int main() {

    // 3 x 3 array - empty bracket so zero initialized
    int arr[3][3] = {};

    // print 1 when column index is above the diagonal
    // when the column size is less than the size of the array minus the size of the row it will print 1
    const int size = 3;
    // loops for each row 0,1,2
    for (int r = 0; r < size; r++){
        // for each column 0,1,2
        for (int c = 0; c < size; c++){
            //checks if the column index is less than 3 - row index
            arr[r][c] = c < size - r;
        }
    }
    // to print the result
    for (int r = 0; r < size; r++) {
        std::cout << "[";
        for (int c = 0; c < size; c++) {
            std::cout << arr[r][c];
            if (c < size - 1) std::cout << "|";
        } 
        std::cout << "]" << std::endl;
    }
    // create a new line after the loop ends so it wont be printed all together
    std::cout << std::endl;

    // 6x6 vector - empty bracket so zero initialized
    const int size6 = 6;
    //created a vector inside a vector named Mtrix
    // will have (size6 - "6 rows"), (vector<int>(size6,0) - "6 columns starting at 0")
    std::vector<std::vector<int>> Mtrix(size6, std::vector<int>(size6,0));
    for (int i = 0; i < size6; i++){
        for (int j = 0; j < size6; j++){
            Mtrix[i][j] = i < size6 - j;
        }
    }
    // to print the result
    for (int i = 0; i < size6; i++) {
        std::cout << "[";
        for (int j = 0; j < size6; j++) {
            std::cout << Mtrix[i][j];
            if (j < size6 - 1) std::cout << "|";
        }
        std::cout << "]" << std::endl;
    }
    // create a new line after the loop ends so it wont be printed all together
    std::cout << std::endl;

    return 0;
}