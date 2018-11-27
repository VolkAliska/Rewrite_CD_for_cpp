// main.cpp

#include "stdafx.h"
#include "command.h"
using namespace std;

int main(){
	
	double pReg, pType1;
	int memTime, calcTime, num;
	cout << "Введите вероятность того, что второй операнд находится в регистре" << endl;
	cin >> pReg;
	cout << "Введите вероятность того, что команда имеет 1 тип" << endl;
	cin >> pType1;
	cout << "Введите количество тактов для обращения к памяти" << endl;
	cin >> memTime;
	cout << "Введите количество тактов для вычисления результата для команд 2 типа" << endl;
	cin >> calcTime;
	cout << "Введите количество команд" << endl;
	cin >> num;

	// создаем массив команд
	Command *list;
	list = new Command[num];
	for(int i = 0; i < num; i++){
		// наполнем его в зависимости от введенных параметров
		Command bufcom;
		bufcom = bufcom.generate(pReg, pType1, memTime, calcTime);
		bufcom.getTimeMas();
		bufcom.appendShift(i);
		list[i] = bufcom;
	}

	for(int i = 0; i < num; i++){
		list[i].print();
	}

	for(int i = 1; i < num; i++){
		int flagConflict = 0; // 0 и 1 для нас норм - потому что можно допустить 2 обращения к памяти одновременно
		for(int j = 0; j < i; j++){
			flagConflict = list[0].comCmp(list[i], list[j], flagConflict);
		}
	}

	delete []list;
	system("pause");
	return 0;
}
