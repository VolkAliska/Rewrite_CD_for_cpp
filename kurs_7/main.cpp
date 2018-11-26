// main.cpp

#include "stdafx.h"
#include "command.h"
using namespace std;

int main(){
	
	double pReg, pType1;
	int memTime, calcTime, num;
	cout << "������� ����������� ����, ��� ������ ������� ��������� � ��������" << endl;
	cin >> pReg;
	cout << "������� ����������� ����, ��� ������� ����� 1 ���" << endl;
	cin >> pType1;
	cout << "������� ���������� ������ ��� ��������� � ������" << endl;
	cin >> memTime;
	cout << "������� ���������� ������ ��� ���������� ���������� ��� ������ 2 ����" << endl;
	cin >> calcTime;
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

	for(int i = 0; i < num; i++){
		list[i].print();
	}
	delete []list;
	system("pause");
	return 0;
}
