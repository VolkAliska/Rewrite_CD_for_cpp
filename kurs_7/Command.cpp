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
	/*cout << "type " << this->type << endl;
	cout << "op2 " << this->op2 << endl;
	cout << "calc " << this->calc << endl;*/
	for (int i = 0; i < this->size; i++){
		if(time[i] == 2)
			cout << " " << " ";
		else if (time[i] == 3)
			cout << "_" << " ";
		else
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
	vector <int>::iterator it;
	it = this->time.begin();
	this->size = 2 + 1 + this->op2 + this->calc + 1; // ��������� ����� �� ������ ��������
										 // �������� � command.h
	this->time.insert(it, 0); // ������ ���� ��� �� ������� �� �������
	it = this->time.begin() + 1;
	this->time.insert(it, 0); // ���� ��� ����������
	it = this->time.begin() + 2;
	this->time.insert(it, 0); // ���� ��� �������� 1 - �������
	it = this->time.begin() + 3;
	int i = 3;
	if (this->op2 == 1){ // ���� 2 ������� �������
		this->time.insert(it, 0); // �� ��� �� ���� ���� �����
		it = this->time.begin() + 4;
	}
	else{ // ���� ������ ������� ��������� � ������
		while(i < this->op2 + 3){ // ������� ������ �������� ������ �� ������
			this->time.insert(it, 1); // 1 � ������� ���� �������� ��������� � ������, ��� ���� �� �����������
			i++; // ������ ������� ������� ������
			it = this->time.begin() + i;
		}
	}
	int cnt = 0;
	while(cnt < this->calc){
		this->time.insert(it, 0); // ����� ��� ���������� ���������� - ���� �� ���������� � ������, ������� 0
		i++;
		it = this->time.begin() + i;
		cnt++;
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

void Command::appendBack(int value){
	for(int i = 0; i < value; i++){
		this->size++;
		this->time.push_back(2);
	}
}

//int Command::comCmp(Command com2, int flagConflict){
//	vector <int>::iterator start1 = this->time.begin();
//	for (int i =0; i<this->time.size(); i++){
//		if((this->time[i] == 1) || (this->time[i] == 5)){
//			start1 = this->time.begin() + i;
//			break;
//		}
//	}
//	int count;
//	count = min(this->time.size(), com2.time.size());
//	int i = 0;
//	//for(int t = 0; t < count; t++){
//	//	if((this->time[t] == 1) && (com2.time[t] == 1)){
//	//		this->time[t] = 5; // inctead 1 (eqv)
//	//	}
//	//}
//	while (count > 0){
//		if(((this->time[i] == 1) || (this->time[i] == 5)) && (com2.time[i] == 5)){
//			this->size++;
//			vector <int>::iterator buf;
//			buf = start1;
//			this->time.insert(start1, 3); // start1 ������ �� ���������
//			for (int k =0; k< this->time.size(); k++){
//				if((this->time[k] == 1) || (this->time[k] == 5)){
//					start1 = this->time.begin() + k;
//					break;
//				}
//			}
//			count++;
//		}
//		if (i < (min(this->time.size(), com2.time.size()) - 1))
//			i = i + 1;
//		
//		count--;
//	}
//	count = min(this->time.size(), com2.time.size());
//	for(int t = 0; t < count; t++){
//		if((this->time[t] == 1) && (com2.time[t] == 1)){
//			this->time[t] = 5; // inctead 1 (eqv)
//		}
//	}
//	return flagConflict;
//}


