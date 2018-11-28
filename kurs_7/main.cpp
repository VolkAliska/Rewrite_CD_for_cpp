// main.cpp

#include "stdafx.h"
#include "command.h"
using namespace std;

int main(){
	
	double pReg, pType1;
	int memTime, calcTime, num;
	cout << "Введите вероятность того, что второй операнд находится в регистре " << endl;
	cout << "0.9 0.8 0.6 " << endl;
	cin >> pReg;
	cout << "Введите вероятность того, что команда имеет 1 тип" << endl;
	cout << "0.9 0.7 0.5 " << endl;
	cin >> pType1;
	cout << "Введите количество тактов для обращения к памяти" << endl;
	cout << "2 5 10 " << endl;
	cin >> memTime;
	cout << "Введите количество тактов для вычисления результата для команд 2 типа" << endl;
	cout << "4 8 16 " << endl;
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
	// ищем максимальную длину команды, чтобы дополнить остальные до ее размера - сделать норм массив из всех 
	int maxsize = 0;
	for(int i = 0; i < num; i++){
		if (list[i].size > maxsize)
			maxsize = list[i].size;
	}

	// дополняем каждую команду до макс длины, чтобы нормально сравнивать потом столбики
	for(int i = 0; i < num; i++){
		int val = maxsize - list[i].size;
		list[i].appendBack(val);
	}

	int isOneHere; // единичка внутри столбика
	for(int i =0; i < maxsize; i++){
		isOneHere = 0;
		for(int j = 0; j < num; j++){
			if (list[j].time[i] == 1){ // нашли первую единичку, нам норм
				if (isOneHere == 0){
					isOneHere = 1;
					continue;
				}
				if (isOneHere == 1){ // нашли вторую единичку, тоже норм
					isOneHere = 2;
					continue;
				}
				if (isOneHere == 2){ // все, нашли третью единичку, но нам можно оставлять только две в одном столбике
					vector <int>::iterator start1; // поэтому ищем начало всех единиц в этой команде
					for (int k =0; k<list[j].time.size(); k++){
						if(list[j].time[k] == 1){
							start1 = list[j].time.begin() + k;
							break;
						}
					}
					list[j].size++;
					maxsize++;
					list[j].time.insert(start1, 3); // и сдвигаем все эти единички вправо
					// 3 - это еквивалент " нет операции "
					for(int r = 0; r < num; r++){ // в этом цикле дополняем все остальные команды справа до длины 
						// этой - потому что мы в нее добавили элемент, значит надо увеличить и остальные команды
						// иначе столбики поедут и все сломакается
						if(r != j)
							list[r].size++;
							list[r].time.push_back(2);
					}
					// снова ищем начало всех единичек, иначе у нас сломается этот итератор (start1)
					for (int k =0; k<list[j].time.size(); k++){
						if(list[j].time[k] == 1){
							start1 = list[j].time.begin() + k;
							break;
						}
					}
					int bufi = i ;
					// выше мы сдвинули "колбасу" из единиц только на 1 позицию вправо, но возможно, что слева были еще единички
					// но нам надо сделать так, чтобы в текущем столбике точно точно не попалась еще одна единичка
					// поэтому тут мы сдвигаем прямо всю "колбасу" на столько позиций, сколько слева от этого
					// столбика еще осталось единиц в этой команде
					while(list[j].time[bufi] == 1){
						list[j].size++;
						list[j].time.insert(start1, 3); 
						/*for(int r = 0; r < num; r++){
							if(r != j)
								list[r].size++;
								list[r].time.push_back(2);
						}*/
						for (int k =0; k<list[j].time.size(); k++){
							if(list[j].time[k] == 1){
								start1 = list[j].time.begin() + k;
								break;
							}
						}
						//bufi--;
					}
				}
			}
		}
	}

	// ищем сумму длин всех команд
	int sum = 0, buftime;
	for(int i = 0; i < num; i++){
		buftime = list[i].getTime();
		sum += buftime;
	}
	int avtime = 0;
	avtime = sum / num; // делим ее на количество команд

	for(int i = 0; i < num; i++){
		list[i].printNice();
	}
	cout << endl << "Среднее время: " << avtime << endl;

	delete []list;
	system("pause");
	return 0;
}
