// lec3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
    srand(time(NULL));
    int bank = 1000;
    int bet;
    int rand_number;
    int choose;
    while (bank > 0)
    {
        cin >> bet;
        while (bet > bank) {
            cout << "Please write right value " << endl;
            cin >> bet;
        }
        bank -= bet;
        rand_number = 1 + rand() % 21;
        cout << "Rand number: " << rand_number;
        cin >> choose;

        if (rand_number - 2 <= choose && rand_number + 2 >= choose) {
            if (rand_number == choose) {
                bet *= 4;
                bank += bet;
                cout << "grats x4" << endl;
            }
            else {
                bet *= 2;
                bank += bet;
                cout << "grats x2" << endl;
            }
        }
        cout << "your balance: " << bank << endl;
    }
    
    return 0;
}
