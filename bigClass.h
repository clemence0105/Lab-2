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
	bigClass(const bigClass& rhv);
	bigClass(char *string); 
	bigClass(long long int v, int base);

	char *str(); 

	// операторы
	bigClass& operator=(const bigClass& rhv); 
	bigClass operator+(const bigClass &right) const;
	bigClass operator-() const; 
	bigClass operator-(const bigClass &right) const;
	bigClass operator*(const bigClass &right) const;
	bigClass operator/(const bigClass &right) const;
	bigClass operator%(const bigClass &right) const;
	bigClass operator^(const bigClass &right) const;

	bool operator>(const bigClass &rhv) const;
	bool operator<(const bigClass &rhv) const;
	bool operator!=(const bigClass &rhv) const;
	bool operator>=(const bigClass &rhv) const;
	bool operator<=(const bigClass &rhv) const;
	bool operator==(const bigClass &rhv) const;

	bool readText(char* filename);
	bool writeText(char* filename);
	bool readBin(char* filename);
	bool writeBin(char* filename);
	
	friend bigClass powModClass(bigClass &base, bigClass &exp, bigClass &mod);
};

#endif