// main.cpp

#include "stdafx.h"
#include "command.h"
using namespace std;

int main(){
	
	double pReg, pType1;
	int memTime, calcTime, num;
	/*cout << "Введите вероятность того, что второй операнд находится в регистре " << endl;
	cout << "0.9 0.8 0.6 " << endl;
	cin >> pReg;
	cout << "Введите вероятность того, что команда имеет 1 тип" << endl;
	cout << "0.9 0.7 0.5 " << endl;
	cin >> pType1;
	cout << "Введите количество тактов для обращения к памяти" << endl;
	cin >> memTime;
	cout << "Введите количество тактов для вычисления результата для команд 2 типа" << endl;
	cin >> calcTime;*/
	pReg = 0.6;
	pType1 = 0.5;
	memTime = 5;
	calcTime = 4;
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

	int maxsize = 0;
	for(int i =0; i < num; i++){
		if (list[i].size > maxsize)
			maxsize = list[i].size;
	}

	for(int i = 0; i < num; i++){
		int val = maxsize - list[i].size;
		list[i].appendBack(val);
	}

	
	for(int i = 0; i < num; i++){
		list[i].print();
	}

	int isOneHere;
	for(int i =0; i < maxsize; i++){
		isOneHere = 0;
		for(int j = 0; j < num; j++){
			if (list[j].time[i] == 1){
				if (isOneHere == 0){
					isOneHere = 1;
					continue;
				}
				if (isOneHere == 1){
					isOneHere = 2;
					continue;
				}
				if (isOneHere == 2){
					vector <int>::iterator start1;
					for (int k =0; k<list[j].time.size(); k++){
						if(list[j].time[k] == 1){
							start1 = list[j].time.begin() + k;
							break;
						}
					}
					list[j].size++;
					maxsize++;
					list[j].time.insert(start1, 3);
					for(int r = 0; r < num; r++){
						if(r != j)
							list[r].size++;
							list[r].time.push_back(2);
					}
					for (int k =0; k<list[j].time.size(); k++){
						if(list[j].time[k] == 1){
							start1 = list[j].time.begin() + k;
							break;
						}
					}
					int bufi = i ;
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

	//for(int i = 1; i < num; i++){
	//	int flagConflict = 0; // 0 и 1 для нас норм - потому что можно допустить 2 обращения к памяти одновременно
	//	for(int j = 0; j < i; j++){
	//		flagConflict = list[i].comCmp(list[j], flagConflict);
	//	}
	//	//list[i].print();
	//}

	//for(int i = 0; i < num; i++){
	//	for(int j = 0; j < list[i].size; j++){
	//		if(list[i].time[j] == 5)
	//			list[i].time[j] = 1;
	//	}
	//}

	for(int i = 0; i < num; i++){
		list[i].print();
	}

	delete []list;
	system("pause");
	return 0;
}
