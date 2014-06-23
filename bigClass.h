#pragma once
#ifndef _BIGCLASS_H_
#define _BIGCLASS_H_
#include "bNum.h"

class bigClass
{
	bNum its;

public:
	//конструкторы
	bigClass(); 
	~bigClass();
	bigClass(bigClass& rhv);
	bigClass(char *string); 
	bigClass(long long int v, int base);

	char *str(); 

	// операторы
	bigClass& operator=(bigClass& rhv); 
	bigClass operator+(bigClass &right);
	bigClass operator-(); 
	bigClass operator-(bigClass &right);
	bigClass operator*(bigClass &right);
	bigClass operator/(bigClass &right);
	bigClass operator%(bigClass &right);
	bigClass operator^(bigClass &right);

	bool operator>(bigClass &rhv);
	bool operator<(bigClass &rhv);
	bool operator!=(bigClass &rhv);
	bool operator>=(bigClass &rhv);
	bool operator<=(bigClass &rhv);
	bool operator==(bigClass &rhv);

	bool readText(char* filename);
	bool writeText(char* filename);
	bool readBin(char* filename);
	bool writeBin(char* filename);
	
	friend bigClass powModClass(bigClass &base, bigClass &exp, bigClass &mod);
};

#endif