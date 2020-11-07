#include <iostream>
#include <cmath>



char * getNumber(char * number) {
    std::cout << "Введите число " << std::endl;
    std::cin.getline(number, 255);
    while (std::cin.fail()) {
        std::cout << "Введите правильное число" << std::endl;
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cin.getline(number, 255);
    }
    return number;
}


char getOperand() {
    char operand;
    while (true) {
        std::cout << "Введите операцию" << std::endl;
        std::cin >> operand;
        std::cin.ignore(32767, '\n');
        if (operand == '+' || operand == '/' || operand == '-' || operand == '*' || operand == '**' || operand == '!') {
            return operand;
        }
        std::cout << "Введите правильный знак операции" << std::endl;
    }

    return operand;
}

//Перевод строки '1' и других в цифру
int translate_to_int(char a) {
    if (a == '1') {
        return 1;
    }
    if (a == '0') {
        return 0;
    }
    if (a == '2') {
        return 2;
    }
    if (a == '3') {
        return 3;
    }
    if (a == '4') {
        return 4;
    }
    if (a == '5') {
        return 5;
    }
    if (a == '6') {
        return 6;
    }
    if (a == '7') {
        return 7;
    }
    if (a == '8') {
        return 8;
    }
    if (a == '9') {
        return 9;
    }
    return 0;
}

void show_result(char* a) {
    for (int i = 0; i < 255; i++) {
        if(a[i] != ' ') {
            std::cout << static_cast<int>(a[i]);
        }
    }
    std::cout << std::endl;
}

void calc(char * num1, char op, char* num2, char *result) {
    
    //Инициализация символами пробела массива для результата
    for (int i = 0; i < 255; i++) {
        result[i] = ' ';
    }
    int number1, number2, iterator;
    if (op == '+') {
        for (int i = strlen(num1)-1, j = strlen(num2)-1; i >= 0 || j >= 0; i--, j--) {
            //когда первое число меньше второго получение цифр 1 9 (пример 80 + 1980)
            if (i < 0 && j >=0) {
                number1 = 0;
                number2 = translate_to_int(num2[j]);

                if (result[j + 1] == ' ') {
                    result[j + 1] = number2;
                }
                else {
                    if (result[j + 1] + number2 >= 10) {
                        result[j + 1] = (result[j + 1] + number2) % 10;
                        if (result[j] == ' ') {
                            result[j] = 1;
                        }
                        else {
                            result[j] += 1;
                        }
                    }
                    else {
                        result[j + 1] += number2;
                    }

                }
            }
            //когда второе число меньше первого получение цифр 1 9 (пример 1982 + 80)
            else if(j < 0 && i >= 0) {
                number1 = translate_to_int(num1[i]);
                number2 = 0;
                if (result[i + 1] == ' ') {
                    result[i + 1] = number1;
                }
                else {
                    if (result[i + 1] + number1 >= 10) {
                        result[i + 1] = (result[i + 1] + number1) % 10;
                        if (result[i] == ' ') {
                            result[i] = 1;
                        }
                        else {
                            result[i] += 1;
                        }
                    }
                    else {
                        result[i + 1] += number1;
                    }

                }
            }
            //еще не известно самое большое число
            else {
                number1 = translate_to_int(num1[i]);
                number2 = translate_to_int(num2[j]);
                //iterator - служит для внесения результта в массив по правильным индексам начиная с эмента под индексом j или i + 1 (так как резульат суммы 2 чисел в худшем случае увеличиться на 1)
                if (i > j) {
                    iterator = i;
                }
                else {
                    iterator = j;
                }
                if (number1 + number2 >= 10) {
                    if (result[iterator + 1] == ' ') {
                        result[iterator + 1] = (number1 + number2) % 10;
                    }
                    else {
                        result[iterator + 1] += (number1 + number2) % 10;
                    }
                    //перенос 1 влево, если там нет ничего то присвоить 1 если что-то уже лежит прибавить
                    if (result[iterator] == ' ') {
                        result[iterator] = 1;
                    }
                    else {
                        result[iterator] += 1;
                    }
                }
                else {
                    if (result[iterator + 1] == ' ') {
                        result[iterator + 1] = number1 + number2;
                    }
                    else {
                        result[iterator + 1] += number1 + number2;
                    }
                }
            }
        }
    }
}



int main()
{
    setlocale(0, "");

    char num1a[255];
    char num2a[255];
    char result[255];
    while(true) {
        calc(getNumber(num1a), getOperand(), getNumber(num2a), result);
        show_result(result);
    }
    return 0;
}