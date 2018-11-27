// main.cpp

#include "stdafx.h"
#include "command.h"
using namespace std;

int main(){
	
	double pReg, pType1;
	int memTime, calcTime, num;
	/*cout << "������� ����������� ����, ��� ������ ������� ��������� � �������� " << endl;
	cout << "0.9 0.8 0.6 " << endl;
	cin >> pReg;
	cout << "������� ����������� ����, ��� ������� ����� 1 ���" << endl;
	cout << "0.9 0.7 0.5 " << endl;
	cin >> pType1;
	cout << "������� ���������� ������ ��� ��������� � ������" << endl;
	cin >> memTime;
	cout << "������� ���������� ������ ��� ���������� ���������� ��� ������ 2 ����" << endl;
	cin >> calcTime;*/
	pReg = 0.6;
	pType1 = 0.5;
	memTime = 5;
	calcTime = 8;
	cout << "������� ���������� ������" << endl;
	cin >> num;

	// ������� ������ ������
	Command *list;
	list = new Command[num];
	for(int i = 0; i < num; i++){
		// �������� ��� � ����������� �� ��������� ����������
		Command bufcom;
		bufcom = bufcom.generate(pReg, pType1, memTime, calcTime);
		bufcom.getTimeMas();
		bufcom.appendShift(i);
		list[i] = bufcom;
	}

	for(int i = 1; i < num; i++){
		int flagConflict = 0; // 0 � 1 ��� ��� ���� - ������ ��� ����� ��������� 2 ��������� � ������ ������������
		for(int j = 0; j < i; j++){
			flagConflict = list[i].comCmp(list[j], flagConflict);
		}
		//list[i].print();
	}

	for(int i = 0; i < num; i++){
		for(int j = 0; j < list[i].size; j++){
			if(list[i].time[j] == 5)
				list[i].time[j] = 1;
		}
	}

	for(int i = 0; i < num; i++){
		list[i].print();
	}

	delete []list;
	system("pause");
	return 0;
}
