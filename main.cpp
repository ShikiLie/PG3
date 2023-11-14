#include <functional>
#include <iostream>
#include <stdio.h>
#include <random>
#include <Windows.h>

using namespace std;

typedef void (*pFunction)(int a, int b);

void SetTimeOut(pFunction function, int second, int diceResult, int playerChoice) {
	Sleep(second * 1000);
	function(diceResult, playerChoice);
}

void Result(int diceResult, int playerChoice) {
	cout << "サイコロの出目は" << diceResult << "で";
	cout << (diceResult % 2 == 0 ? "偶数" : "奇数") << "です" << endl;
	
	if ((diceResult % 2 == 0 && playerChoice == 2) || (diceResult % 2 == 1 && playerChoice == 1)) {
		cout << "当たり" << endl;
	}
	else {
		cout << "外れ" << endl;
	}
}

int PlayerChoice() {
	int playerChoice = 0;

	while (playerChoice != 1 && playerChoice != 2) {
		cout << "奇数か偶数を選択してEnterを押してください" << std::endl;
		cout << "1 : 奇数, 2 : 偶数" << endl;
		cin >> playerChoice;
	}

	return playerChoice;
}

int main(void) {
	std::random_device rd;
	std::mt19937 mt(rd());

	int playerChoice = PlayerChoice();

	std::function<int()>diceRoll = [&mt]() {
		return mt() % 6 + 1;
		};

	int diceResult = diceRoll();

	pFunction result = Result;

	SetTimeOut(result, 3, diceResult, playerChoice);

	return 0;
}
