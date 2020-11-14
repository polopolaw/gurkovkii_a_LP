#include <iostream>
#include <cmath>



char * getNumber(char * number) {
    //todo реализовать возможность введения отрицательных чисел.
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

int compare(char* num1, char* num2) {
    int flag = 0;
    //10 - 5 = 5  5 - 10 = -5  10 + 5 = 15  15 - 10
        //to do определить какое число самое большое. 885 885 0
    if (strlen(num1) - 1 > strlen(num2) - 1) {
        flag = 1;
    }
    else if (strlen(num1) - 1 < strlen(num2) - 1) {
        flag = 2;
    }
    else {
        
        for (int i = 0; i < strlen(num1) - 1; i++) {
            if (num1[i] > num2[i]) {
                flag = 1;
                break;
            }
            else if (num1[i] < num2[i]) {
                //num1<num2
                flag = 2;
                break;
            }
        }
    }
    
    return flag;
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
    if (op == '-') {
        //-555 - -555
        //555 - 555
        //@todo обработать вот эти случаи:
        //! 500 - -500
        //! -500 - 500
        int flag = compare(num1, num2);
        if (flag == 0) {
            result[0] = 0;
            return;
        }

        //num1>num2
        //909999991 - 258
        if (flag == 1) {
            //todo проверить привальность условия в цикле
            for (int i = strlen(num1) - 1, j = strlen(num2) - 1; i >= 0 || j >= 0; i--, j--) {
                number1 = translate_to_int(num1[i]);
                number2 = translate_to_int(num2[j]);
                if (number1 - number2 < 0) {
                    result[i] = 10 + number1 - number2;
                    int counter = 0; 
                    for (int k = i - 1; translate_to_int(num1[k]) == 0; k--) {
                        num1[k] = 9;
                        counter = k;
                    }
                    if (translate_to_int(num1[counter]) == 1 && counter == 0) {
                        num1[counter] == ' ';
                    }
                    else {
                        num1[counter] -= 1;
                    }
                    
                }
                else {
                    result[i] = num1[i] - num2[j];
                }
            }
            
        }
        //num1<num2
        if (flag == 2) {

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
        getNumber(num1a);
        getNumber(num2a);
        calc(num1a, getOperand(), num2a, result);
        show_result(result);
    }
    return 0;
}
