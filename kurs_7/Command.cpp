// Command.cpp

#include "stdafx.h"
#include "Command.h"
using namespace std;

Command::Command(){
	this->type = 0;
	this->op2 = 0;
	this->calc = 0;
}

void Command::print(){
	cout << "type " << this->type << endl;
	cout << "op2 " << this->op2 << endl;
	cout << "calc " << this->calc << endl;
	for (int i = 0; i < this->size; i++){
		cout << time[i] << " ";
	}
	cout << endl;
}

Command Command::generate(double pReg, double pType1, int memTime, int calcTime){
	Command com;
	if((rand() % 100) < (pReg * 100)){ // ������� ������ ����������� 
		com.op2 = 1; // ���� �� ������ � "�������" ����������� ����, ��� 2 ������� - �������,
					   // �� ������� �������� 1 ����
	}
	else
		com.op2 = memTime;
	if((rand() % 100) < (pType1 * 100)){ // ������� ������ ����������� 
		com.calc = 1; // ���� �� ������ � "�������" ����������� ����, ��� ������� ����� 1 ���
					    // ��� ���������� ���������� �������� 1 ����
		com.type = 1;
	}
	else{
		com.type = 2;
		com.calc = calcTime;
	}
	return com;
}

void Command::getTimeMas(){
	this->size = 2 + 1 + op2 + calc + 1; // ��������� ����� �� ������ ��������
										 // �������� � command.h
	this->time = new int[this->size];
	this->time[0] = 0; // ������ ���� ��� �� ������� �� �������
	this->time[1] = 0; // ���� ��� ����������
	this->time[2] = 0; // ���� ��� �������� 1 - �������
	int i = 3;
	if (op2 == 1) // ���� 2 ������� �������
		time[3] = 0; // �� ��� �� ���� ���� �����
	else{ // ���� ������ ������� ��������� � ������
		while(i < op2 + 3){ // ������� ������ �������� ������ �� ������
			time[i] = 1; // 1 � ������� ���� �������� ��������� � ������, ��� ���� �� �����������
			i++; // ������ ������� ������� ������
		}
	}
	while(i < this->size - 1){
		time[i] = 0; // ����� ��� ���������� ���������� - ���� �� ���������� � ������, ������� 0
		i++;
	}
	time[size-1] = 1; // ������ ���������� - ��� ��������� � ������, ������� 1
}