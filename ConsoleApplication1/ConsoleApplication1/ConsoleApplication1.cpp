#include<iostream>
#include<ctime>
#include<Windows.h>

using namespace std;

void loading();

void main() {
	setlocale(0, "");
	srand(static_cast<unsigned int>(time(nullptr)));
	bool flag = true;

	int balance = 1000;
	int betBalance;
	int bet;
	int casinoBet;

	do {
		casinoBet = (rand() % 21) + 1;

		cout << "Ñäåëàéòå ñòàâêó !!!" << endl << endl;
		cout << "Áàëàíñ - " << balance << endl;
		cout << "Ñòàâêà - ";
		cin >> betBalance; cout << endl;
		cout << "Âûáåðèòå ÷èñëî îò 1 äî 21 -- ";
		cin >> bet; cout << endl;

		balance = balance - betBalance;

		cout << endl;
		loading();
		system("cls");

		//cout << balance; system("pause");

		if (bet == casinoBet - 1 || bet == casinoBet - 2 || bet == casinoBet + 1 || bet == casinoBet + 2) {
			betBalance = betBalance * 2;
			cout << "Âûèãðûøü Õ2 !" << endl;
			balance = balance + betBalance;
			system("pause");
		}
		else if (bet == casinoBet) {
			betBalance = betBalance * 4;
			cout << "Âûèãðûøü Õ4 !" << endl;
			balance = balance + betBalance;
			system("pause");
		}
		else {
			cout << "Ñòàâêà íå ïðîøëà :(" << endl;
			system("pause");
		}


		if (balance <= 0) {
			flag = false;
			cout << "Òû ïðîèãðàë!!! Çàõîäè êîãäà áóäóò äåíüãè :)" << endl;
			system("pause");
		}
		if (balance >= 2000) {
			flag = false;
			cout << "Ïîçäðàâëÿþ! Òû âûèãðàë!" << endl;
			system("pause");
		}

		system("cls");
	} while (flag == true);
}

void loading() {
	string a1 = { "Áàðàáàí êðóòèòñÿ." };
	string a2 = { "Áàðàáàí êðóòèòñÿ.." };
	string a3 = { "Áàðàáàí êðóòèòñÿ..." };

	for (int i = 0; i < 5; i++) {
		system("cls");
		cout << a1;
		Sleep(90);
		system("cls");
		cout << a2;
		Sleep(90);
		system("cls");
		cout << a3;
		Sleep(90);
	}
}