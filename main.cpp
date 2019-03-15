#include "funcshen.hpp"
#include <fstream>

using namespace std;

void OpenFileTest(void)
{
	double x[4], y[4];
	
	std::cout << "������� ��� ����� ��� �����: ";
	char fNameTest[255], filen[245],ffolder[10] = "testfile\\";
	std::cin >> filen;
	for(int i = 0; i < 255; i++)
	{
		if(i < 10)
		{
			fNameTest[i] = ffolder[i];
		}
		else
		{
			fNameTest[i-1] = filen[i-10];
			if(filen[i-10] == '\0')
			{
				break;
			}
		}
	}
	ifstream FileTest(fNameTest);
	for(int ctr = 0; ctr < 4; ctr++)
	{
		FileTest >> x[ctr];
		FileTest >> y[ctr];
	}
	FileTest.close();
	std::cout << "������� �������� ����� ��� ���������� ����������: ";
	char fSiveName[100];
	std::cin >> fSiveName;
	ofstream fout(fSiveName);
	figure f1(x[0],y[0], x[1],y[1], x[2],y[2], x[3],y[3]);
	if (!testFigure(f1))
	{
		std::cout << endl << "��������������� �� ��������" << endl;
		fout << "��������������� �� ��������" << endl;
		std::cout << "������� �����: " << square(f1) << endl;
		fout << "������� �����: " << square(f1) << endl;
	}
	else
	{
		std::cout << "������� �������� ��������" << endl;
		fout << "��������������� ��������" << endl;
	}
	fout.close();
}

int main(void) 
{
	setlocale(LC_ALL,"Russian");

	OpenFileTest();

	return 0;
}
