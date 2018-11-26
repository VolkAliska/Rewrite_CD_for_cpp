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
	if((rand() % 100) < (pReg * 100)){ // ручками делаем вероятность 
		com.op2 = 1; // если мы попали в "область" вероятности того, что 2 операнд - регистр,
					   // то операнд занимает 1 такт
	}
	else
		com.op2 = memTime;
	if((rand() % 100) < (pType1 * 100)){ // ручками делаем вероятность 
		com.calc = 1; // если мы попали в "область" вероятности того, что команда имеет 1 тип
					    // тут вычисление результата занимает 1 такт
		com.type = 1;
	}
	else{
		com.type = 2;
		com.calc = calcTime;
	}
	return com;
}

void Command::getTimeMas(){
	this->size = 2 + 1 + op2 + calc + 1; // посчитали такты за каждую операцию
										 // подробно в command.h
	this->time = new int[this->size];
	this->time[0] = 0; // чтение кода нас не смущает по условию
	this->time[1] = 0; // такт для дешифрации
	this->time[2] = 0; // такт для операнда 1 - регистр
	int i = 3;
	if (op2 == 1) // если 2 операнд регистр
		time[3] = 0; // то нам на него тоже пофиг
	else{ // если второй операнд находится в памяти
		while(i < op2 + 3){ // сколько тактов занимает чтение из памяти
			time[i] = 1; // 1 в массиве тайм означает обращение к памяти, нам надо их отслеживать
			i++; // просто смотрим текущий индекс
		}
	}
	while(i < this->size - 1){
		time[i] = 0; // такты для вычисления результата - тоже не обращаемся к памяти, поэтому 0
		i++;
	}
	time[size-1] = 1; // запись результата - это обращение к памяти, поэтому 1
}