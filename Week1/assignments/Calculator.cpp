#include <iostream>

int main(){
    // using double for larger values and decimals.
    double Num1 = 0;
    double Num2 = 0;
    char choiceOP; // char to use characters as operators(+, -, x, *, /, %)

    std::cout << "Instructions: 1) This basic calculator only allows single expressions in the following order (number, operator, number)" << std::endl;
    std::cout << "2) The calculator doesn't allow chain expressions and will not divide by zero" << std::endl;
    std::cout << "3) If not followed the calculator will turn off" << std::endl;

    std::cout << "Enter an expression to calculate (example: 3 x 3)" << std::endl;
    
    // Check the input order. user wont be able to type two nums and then the operator
    while(std::cin >> Num1 >> choiceOP >> Num2) {

    if (choiceOP == 'X') choiceOP = 'x';
    
    if (choiceOP != 'x' && choiceOP != '*' && choiceOP != '+' && choiceOP != '-' && choiceOP != '/' && choiceOP != '%') {
        std::cout << "Error, use a valid operator (+, -, x, *, /, %)" << std::endl;
        continue;
    }
    // User wont be able to divide by 0
    if ((choiceOP == '/' || choiceOP == '%') && Num2 == 0) {
        std::cout << "UNDEFINED, Unable to divide by Zero" << std::endl;
        continue;
    }
    //new double called result to be able to perform the operations
    double result = 0;
    // Using switch to perform the operation based on each operational symbol
    switch (choiceOP) {
        case '+':
        result = Num1 + Num2;
        break;
        
        case '-':
        result = Num1 - Num2;
        break;

        case 'x':
        case '*':
        case 'X':
        result = Num1 * Num2;
        break;

        case '/':
        result = Num1 / Num2;
        break;

        case '%':
        result = (int)Num1 % (int)Num2;
        break;
    }

    // print the result
    std::cout << "Your result is: " << Num1 << " " << choiceOP << " " << Num2 << " = " << result << std::endl;


}
    //Prints only if the user enters an invalid input and the program closes.

    std::cout << "Invalid input, please follow the instructions given in the beggining" << std::endl;

    return 0;
}
