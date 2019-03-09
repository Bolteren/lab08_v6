#include <iostream>
#include <cmath>
#include <string>
#define pi 3.14159

using namespace std;


int modl(int a)
{
	if (a < 0)
	{
		return (-1 * a);
	}
	return a;
}

double modl(double a)
{
	if (a < 0)
	{
		return (-1 * a);
	}
	return a;
}

class coord
{
	public:
		double x;
		double y;
	coord(double x1=0.0, double y1=0.0): x(x1), y(y1)
    {
    }
    
	coord operator- (coord v0)
	{
		coord v3;
		v3.x = this->x - v0.x;
		v3.y = this->y - v0.y;
		return v3;
	}
	friend std::ostream& operator<< (std::ostream &out, const coord &v1)
	{
		out << "(x = " << v1.x << " , y = " << v1.y << " )";
		return out;
	}
	coord* initial(double x1, double y1)
	{
		this->x = x1;
		this->y = y1;
		return this;
	}
};

class figure
{
	public:
		coord mCoord[4];
};


coord vctr(coord v0, coord v1) // v1 - конечная точка v0 - начальная точка
{
	coord v1v0;
	v1v0 = v1 - v0;
	return v1v0;
}

double testPoint(coord v0, coord v1, coord vtest)
{
	double a,b,c, dtest;
	a = v1.y - v0.y;
	b = v0.x - v1.x;
	c = v1.x * v0.y - v0.x * v1.y;
	dtest = a * vtest.x + b * vtest.y + c;
	return dtest;
}
bool testArr(double *arr)
{
	bool tst = false;
	double test1 = 0.0, test2 = 0.0;
	for(int counter = 0; counter < 8; counter ++)
	{
		test1 += arr[counter];
	}
	for(int counter = 0; counter < 8; counter ++)
	{
		test2 += modl(arr[counter]);
	}
	test1 = modl(test1);
//	cout << "test1 == " << test1 << "test2 == " << test2;
	if(test1 == test2)
	{
		tst = true;
	}
	else tst = false;
	return tst;
}
bool testFigure(figure f1)
{
	int counter = 3, ctrTest = 0;
	double Tst[8];
	for(int i = 0; i < 4; i ++)
	{
		int tmp = 0;
		for(int ctr = 1; ctr < 3; ctr ++)
		{
			if( i < 2)
			{
				int temp = i + ctr, tmp = 0;
				Tst[ctrTest] = testPoint(f1.mCoord[counter],f1.mCoord[i],f1.mCoord[temp]);
				ctrTest++;
				
			}
			else if( i == 2)
			{
				int temp = i + ctr;
				Tst[ctrTest] = testPoint(f1.mCoord[counter],f1.mCoord[i],f1.mCoord[temp]);
				ctrTest++;
			}
			else
			{
				int temp = i + ctr - 4;
				Tst[ctrTest] = testPoint(f1.mCoord[counter],f1.mCoord[i],f1.mCoord[temp]);
				ctrTest++;
			}
		}
		if(counter == 3)
		{
			counter = 0;
		}
		else counter++;
	}
	
	return testArr(Tst);
}

int main(void) 
{
	figure f1, f2;
	f1.mCoord[0].initial(1, 1);
	f1.mCoord[1].initial(8, 2);
	f1.mCoord[2].initial(7, 5);
	f1.mCoord[3].initial(2, 5);
	
	
	f2.mCoord[0].initial(2, 2);
	f2.mCoord[1].initial(8, 1);
	f2.mCoord[2].initial(5, 2);
	f2.mCoord[3].initial(7, 4);
	cout << "f1 = " << testFigure(f1) << " f2 = " << testFigure(f2) << endl;
	
	return 0;
}
