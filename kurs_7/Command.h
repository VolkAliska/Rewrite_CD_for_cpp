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
	std::vector<int> time;

	Command();
	Command generate(double pReg, double pType1, int memTime, int calcTime);
	void getTimeMas();
	void appendShift(int value);
	void appendBack(int value);
	void print();
	void printNice();
	int getTime();
	~Command(){}
};