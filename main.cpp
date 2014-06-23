#include <iostream>
#include "bigClass.h"
#include <string.h>
using namespace std;

int main(int argc, char* argv[])
{
	char *file1 = argv[1]; // ���������� �� ������ ������� ������� ����������
	char op = argv[2][0];
	char *file2 = argv[3];
	char *fileRes = argv[4];
	char *fileMod = NULL; // �� ����������� ������� -b
	
	int bin = 0; //�����. ���������� ��� ��������� �����
	
	if (argc == 6)
	{
		if (!strcmp(argv[5], "-b"))// ���� ����� �������� ����� -b, �� �������� � ��������� �������
			bin = 1;
		else
			fileMod = argv[5];
	}

	if (argc == 7)
	{
		bin = 1;
		fileMod = argv[6];
	}

	bigClass n, m, md; 

	if (bin == 1)
	{
		n.readBin(file1);
		m.readBin(file2);
		if (fileMod != NULL)
			md.readBin(fileMod);
	}
	else
	{
		n.readText(file1);
		m.readText(file2);
		if (fileMod != NULL)
			md.readText(fileMod);
	}

	bigClass k; 
	if (argv[2][0] == '+')
	{
		k = n + m;
	}

	if (argv[2][0] == '-')
	{
		k = n - m;
	}


	if (argv[2][0] == '*')
	{
		k = n * m;
	}

	if (argv[2][0] == '/')
	{
		k = n / m;
	}

	if (argv[2][0] == '%')
	{
		k = n % m;
	}

	if (fileMod != NULL) // ���� ����� ���� � �������, �� ��������� ����� �������� ����� ��������� �� ����� ������
	{
		k = k % md;
	}

	if (argv[2][0] == '^')
	{
		if (fileMod == NULL)
		{
			k = n ^ m;
		}
		else
		{
			k = powModClass(n, m, md);
		}
	}

	if (bin == 1)
	{
		k.writeBin(fileRes);
	}
	else
		k.writeText(fileRes);

	/*bigClass a = 2;
	bigClass b = "10999";
	bigClass c = a + b;
	if (a != b)
	{
		cout << "��� �����";
	}
	//if (c.writeBin("1.dat") == false)
	/*{
		cout << "Can't read" << endl;
		return 0;
	}*/
	//cout << c.str();
	return 0;
}