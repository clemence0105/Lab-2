#include "bigClass.h"


bigClass::bigClass()
{
	this->its.base = 0;
	this->its.nums = NULL;
	this->its.size = 0;
	this->its.sign = -1;
}

bigClass::bigClass(bigClass& rhv)
{
	this->its = copy(rhv.its);
}

bigClass::bigClass(char *string)
{
	this->its = StructFromStr(string);
}

bigClass::bigClass(long long int v, int base)
{
	this->its = fromInt(v, base);
}

bigClass::~bigClass()
{
	if (this->its.nums != NULL)
	{
		free(this->its.nums);
	}
}

bigClass& bigClass::operator=(bigClass& rhv)
{
	if (this->its.nums != NULL)
	{
		free(this->its.nums);
	}
	this->its = copy(rhv.its);
	return *this;
}

char * bigClass::str()
{
	return getString(this->its);
}

bigClass bigClass::operator+(bigClass &right)
{
	bigClass res;
	res.its = Sum1(this->its, right.its);
	return res;
}

bigClass bigClass::operator-()
{
	bigClass res;
	res.its = mins(this->its);
	return res;
}

bigClass bigClass::operator-(bigClass &right)
{
	return *this + (-right);
}

bigClass bigClass::operator*(bigClass &right)
{
	bigClass res;
	res.its = mul(this->its, right.its);
	return res;
}

bigClass bigClass::operator/(bigClass &right)
{
	bigClass ost;
	bigClass res;
	res.its = dividing(this->its, right.its, &ost.its);
	return res;
}

bigClass bigClass::operator%(bigClass &right)
{
	bigClass ost;
	bigClass res;
	res.its = dividing(this->its, right.its, &ost.its);
	return ost;
}

bigClass bigClass::operator^(bigClass &right)
{
	bigClass res;
	res.its = pPow(this->its, right.its);
	return res;
}

bool bigClass::readText(char* filename)
{
	bigClass res;
	res.its = ReadFromTFile(filename);
	if (res.its.nums == 0)
	{
		return false;
	}
	else
	{
		*this = res;
		return true;
	}
}

bool bigClass::readBin(char* filename)
{
	bigClass res;
	res.its = ReadFromBFile(filename);
	if (res.its.nums == 0)
	{
		return false;
	}
	else
	{
		*this = res;
		return true;
	}
}

bool bigClass::writeText(char* filename)
{
	return WriteToTFile(filename, this->its) == 0;
}

bool bigClass::writeBin(char* filename)
{
	return WriteToBFile(filename, this->its) == 0;
}

bool bigClass::operator>(bigClass &rhv)
{
	return compare(this->its, rhv.its) > 0;
}

bool bigClass::operator<(bigClass &rhv)
{
	return compare(this->its, rhv.its) < 0;
}

bool bigClass::operator>=(bigClass &rhv)
{
	return compare(this->its, rhv.its) >= 0;
}

bool bigClass::operator<=(bigClass &rhv)
{
	return compare(this->its, rhv.its) <= 0;
}

bool bigClass::operator==(bigClass &rhv)
{
	return compare(this->its, rhv.its) == 0;
}

bool bigClass::operator!=(bigClass &rhv)
{
	return compare(this->its, rhv.its) != 0;
}

bigClass powModClass(bigClass &base, bigClass &exp, bigClass &mod)
{
	bigClass res;
	res.its = powMod(base.its, exp.its, mod.its);
	return res;
}