// main.cpp

#include "stdafx.h"
#include "command.h"
using namespace std;

int main(){
	
	double pReg, pType1;
	int memTime, calcTime, num;
	cout << "¬ведите веро€тность того, что второй операнд находитс€ в регистре" << endl;
	cin >> pReg;
	cout << "¬ведите веро€тность того, что команда имеет 1 тип" << endl;
	cin >> pType1;
	cout << "¬ведите количество тактов дл€ обращени€ к пам€ти" << endl;
	cin >> memTime;
	cout << "¬ведите количество тактов дл€ вычислени€ результата дл€ команд 2 типа" << endl;
	cin >> calcTime;
	cout << "¬ведите количество команд" << endl;
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
	delete []list;
	system("pause");
	return 0;
}
