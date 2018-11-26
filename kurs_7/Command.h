// Command.h

#include "stdafx.h"

class Command{
public:
	int type; 
	int op2; 
	int calc;
	/*
	������: ������ ���� ��������, ���������� - 2 �����
	������� 1 - 1 ����
	������� 2 - op2 ������
	���������� - calc ������
	������ ���������� - 1 ����
	*/
	int size;
	int* time; 

	Command();
	Command generate(double pReg, double pType1, int memTime, int calcTime);
	void print();
	void getTimeMas();
	void appendShift(int value);
	~Command(){}
};