// Command.h

#include "stdafx.h"

class Command{
public:
	int type; 
	int op2; 
	int calc;
	/*
	логика: чтение кода операции, дешифрация - 2 такта
	операнд 1 - 1 такт
	операнд 2 - op2 тактов
	вычисление - calc тактов
	запись результата - 1 такт
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