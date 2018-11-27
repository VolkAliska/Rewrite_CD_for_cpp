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
	this->size = 2 + 1 + this->op2 + this->calc + 1; // ��������� ����� �� ������ ��������
										 // �������� � command.h
	this->time.push_back(0); // ������ ���� ��� �� ������� �� �������
	this->time.push_back(0); // ���� ��� ����������
	this->time.push_back(0); // ���� ��� �������� 1 - �������
	int i = 3;
	if (this->op2 == 1) // ���� 2 ������� �������
		this->time.push_back(0); // �� ��� �� ���� ���� �����
	else{ // ���� ������ ������� ��������� � ������
		while(i < this->op2 + 3){ // ������� ������ �������� ������ �� ������
			this->time.push_back(1); // 1 � ������� ���� �������� ��������� � ������, ��� ���� �� �����������
			i++; // ������ ������� ������� ������
		}
	}
	while(i < this->size - 1){
		this->time.push_back(0); // ����� ��� ���������� ���������� - ���� �� ���������� � ������, ������� 0
		i++;
	}
	this->time.push_back(1); // ������ ���������� - ��� ��������� � ������, ������� 1
}

void Command::appendShift(int value){
	for(int i = 0; i < value; i++){
		vector <int>::iterator it;
		it = this->time.begin();
		this->size++;
		//this->time.resize(this->size);
		this->time.insert(it, 2);
	}
}

int Command::comCmp(Command com1, Command com2, int flagConflict){
	vector <int>::iterator start1 = com1.time.begin();
	for (int i =0; i<com1.time.size(); i++){
		if(com1.time[i] == 1){
			start1 = com1.time.begin() + i;
			break;
		}
	}
	int count;
	count = min(com1.time.size(), com2.time.size());
	int i = 0;
	while (count > 0){
		count--;
		if((com1.time[i] == 1) && (com1.time[i] == com2.time[i])){
			if(flagConflict == 0){
				flagConflict++;
				break;
			}
			if(flagConflict == 1){
				com1.size++;
				com1.time.insert(start1, 3); // start1 ������ �� ���������
				for (int k =0; k<com1.time.size(); k++){
					if(com1.time[k] == 1){
						start1 = com1.time.begin() + k;
						break;
					}
				}
				count++;
			}
		}
		if (i < (min(com1.time.size(), com2.time.size()) - 1))
			i = i + 1;
	}
	return flagConflict;
}