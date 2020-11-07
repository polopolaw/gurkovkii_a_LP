#include <iostream>
#include <cmath>

//+ , - , * , /, **, !
/*
double getNumber() {
    double number;
    std::cout << "Введите число " << std::endl;
    std::cin >> number;
    while(std::cin.fail()) {
        std::cout << "Введите правильное число" << std::endl;
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cin >> number;
    }
    std::cin.ignore(32767, '\n');
    return number;
}


char getOperand() {
    char operand;
    while (true) {
        std::cout << "Введите операцию" << std::endl;
        std::cin >> operand;
        if (operand == '+' || operand == '/' || operand == '-' || operand == '*' || operand == '**' || operand == '!') {
            return operand;
        }
        std::cout << "Введите правильный знак операции" << std::endl;
    }
    
    return operand;
}

double factorial(double num) {
    
    double result = num;
    if (num == 0) {
        return 1;
    }
    return num * factorial(num - 1);
}


double calc(double num1, char op, double num2) {
    if (op == '+') {
        return num1 + num2;
    }

    if (op == '/') {
        return num1 / num2;
    }

    if (op == '-') {
        return num1 - num2;
    }

    if (op == '*') {
        return num1 * num2;
    }

    if (op == '**') {
        return pow(num1, num2);
    }

    if (op == '!') {
        return factorial(num1);
    }
}



int main()
{
    setlocale(0, "");
    double result = calc(getNumber(), getOperand(), getNumber());
    std::cout.precision(40);
    std::cout << result;
    return 0;
}