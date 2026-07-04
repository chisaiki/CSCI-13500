#include <iostream>

// Reminder: function details are in the spec PDF

void Print2DArray(const int arr_input[][3], const int total_rows){

    std::cout << "Initializing function: Print2DArray\n\n";

    // Prints the matrix, O(n^2) nested loop

    for(int row_idx = 0; row_idx < total_rows; row_idx++){
        std::cout << "[";
        for (int col_idx = 0; col_idx < 3; col_idx++){
            std::cout << arr_input[row_idx][col_idx];
            if(col_idx < 2){
                std::cout << "|";
            }
        }
        std::cout << "]\n";
    }

    std::cout << "\nEnding function: Print2DArray\n\n";
}

void MatrixAddition(const int arr_first[][3], const int first_rows_total,
                    const int arr_second[][3], const int second_rows_total)
    {
        std::cout << "Starting function: MatrixAddition\n\n";

        // Matrix must equal to each other to add
        if (first_rows_total != second_rows_total){
            std::cout << "Matrices must be of the same dimensions to be added.";
            std::cout << "\nTerminating  function: MatrixAddition\n\n";
            return;
        }

        static int addition_result[3][3];

        // Add cells and prints result, O(n^2)

        for(int r_pos = 0; r_pos < first_rows_total; r_pos++){
            std::cout << "[";
            for(int c_pos = 0; c_pos < 3; c_pos++){
                addition_result[r_pos][c_pos] = arr_first[r_pos][c_pos] + arr_second[r_pos][c_pos];
                std::cout << addition_result[r_pos][c_pos];
                if (c_pos < 2){
                    std::cout << "|";
                }
            }
            std::cout << "]\n";
        }

        std::cout << "\nTerminating  function: MatrixAddition\n\n";
    }

void TransposeMatrix(const int arr_input[][3], const int total_rows){
    std::cout << "Initializing function: TransposeMatrix\n\n";

    // Swap rows and columns
    // O(n * m) - loop limits can differ for non-square matrices
    for(int src_col = 0; src_col < 3; src_col++){
        std::cout << "[";
        for(int src_row = 0; src_row < total_rows; src_row++){
            std::cout << arr_input[src_row][src_col];
            if(src_row < total_rows - 1){
                std::cout << "|";
            }
        }
        std::cout << "]\n";
    }

    std::cout << "\nTerminating  function: TransposeMatrix\n\n";
}

// O(1) - no loops needed
void Determinant(const int arr_input[][3], const int dimension_size){
    std::cout << "Initializing function: Determinant\n\n";

    int det_value = 0;

    // Only 2x2 and 3x3 are supported
    if (dimension_size == 2){
        det_value = (arr_input[0][0] * arr_input[1][1]) - (arr_input[0][1] * arr_input[1][0]);
    } else if (dimension_size == 3){
        det_value =   (arr_input[0][0]*
                        ((arr_input[1][1] * arr_input[2][2]) -
                        (arr_input[1][2] * arr_input[2][1]))) -
                        (arr_input[0][1]*
                        ((arr_input[1][0]*arr_input[2][2]) -
                        (arr_input[1][2]*arr_input[2][0]))) +
                        (arr_input[0][2]*
                        ((arr_input[1][0]*arr_input[2][1]) -
                        (arr_input[1][1]*arr_input[2][0])));
    } else {
        std::cout << "You want me to find the determinant of a matrix beyond 3x3!? Hell nah.";
        std::cout << "\nTerminating  function: Determinant\n\n";
        return;
    }

    std::cout << "The determinant of the matrix is: " << det_value << std::endl;

    std::cout << "\nTerminating  function: Determinant\n\n";
}

void SearchValue(const int arr_input[][3], const int total_rows, const int search_target){
    std::cout << "Initializing function: SearchValue\n\n";

    bool found_flag = false;

    // Check every cell for the target value
    // O(n^2)
    for(int row_scan = 0; row_scan < total_rows; row_scan++){
        for(int col_scan = 0; col_scan < 3; col_scan++){
            if(arr_input[row_scan][col_scan] == search_target){
                found_flag = true;
                std::cout << "Target '" << search_target << "' was found at [" << row_scan << "],[" << col_scan << "]" << std::endl;
            }
        }
    }
    if(!found_flag){
        std::cout << "Target was not found in the matrix.\n";
    }

    std::cout << "\nTerminating  function: SearchValue\n\n";
}

void MatrixMultiplication(const int arr_left[][3], const int arr_right[][3],
                          const int left_rows, const int left_cols,
                          const int right_rows, const int right_cols){

    std::cout << "Initializing function: MatrixMultiplication\n\n";

    // Left columns must match right rows
    if(left_cols != right_rows){
        std::cout << "Matrix Multiplication cannot be performed." << std::endl;
        std::cout << "\nTerminating  function: MatrixMultiplication\n\n";
        return;
    }

    static int product_result[3][3];

    // Multiply and print the result
    // O(n^3) - extra loop to sum each cells products
    for(int r_out = 0; r_out < left_rows; r_out++){
        std::cout << "[";
        for (int c_out = 0; c_out < right_cols; c_out++){
            for(int k_sum = 0; k_sum < left_cols; k_sum++){
                product_result[r_out][c_out] += arr_left[r_out][k_sum] * arr_right[k_sum][c_out];
            }
            std::cout << product_result[r_out][c_out];
            if(c_out < 2){
                std::cout << "|";
            }
        }
        std::cout << "]\n";
    }

    std::cout << "\nTerminating function: MatrixMultiplication\n\n";
}

int main(){
    // Samples
    int demo_matrix_a[3][3] = {
        {1,8,9},
        {3,5,3},
        {1,4,3},
    };

    int demo_matrix_b[3][3] = {
        {99,33,22},
        {12,4,76},
        {12,3,43}
    };

    // Get matrix dimensions from sizeof instead of hardcoding them
    int rows_a = sizeof(demo_matrix_a)/sizeof(demo_matrix_a[0]);
    int cols_a = sizeof(demo_matrix_a[0])/sizeof(demo_matrix_a[0][0]);

    std::cout << "row: " << rows_a << " col: " << cols_a << std::endl << std::endl;

    Print2DArray(demo_matrix_a, rows_a);

    MatrixAddition(demo_matrix_a, 3, demo_matrix_b, 3);

    TransposeMatrix(demo_matrix_a, rows_a);

    Determinant(demo_matrix_b, 3);

    SearchValue(demo_matrix_a, 3, 2);

    MatrixMultiplication(demo_matrix_a, demo_matrix_b, rows_a, cols_a, 3, 3);

    return 0;
}