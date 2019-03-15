#include "funcshen.hpp"


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

double testPoint(coord v0, coord v1, coord vtest)
{
	double a,b,c, dtest;
	a = v1.y - v0.y;
	b = v0.x - v1.x;
	c = v1.x * v0.y - v0.x * v1.y;
	dtest = a * vtest.x + b * vtest.y + c;
	return dtest;
}

int testArr(double *arr)
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
	if(test1 == test2)
	{
		tst = true;
	}
	else tst = false;
	return tst;
}

int testFigure(figure f1)
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
//	std::cout << " " << "\b";//без этого работает не правильно, хз почему.
	return testArr(Tst);
}

double square(figure tsFig)
{
	/*-------------------------------*/
	double x[4];  
	double y[4];
	double s, res = 0;
 
	int n = 4;
	
	for (int i = 0; i < n; i++) 
	{
    	x[i] = tsFig.mCoord[i].x; 
    	y[i] = tsFig.mCoord[i].y; 
   	}

	for (int i = 0; i < n; i++) 
	{
    	if (i == 0) 
		{
       		s = x[i]*(y[n-1] - y[i+1]);
       		res += s;
     	}
    	else	if (i == n-1) 
		{
	 		s = x[i]*(y[i-1] - y[0]);
	 		res += s;
       	}
     	else 
		{
       		s = x[i]*(y[i-1] - y[i+1]);
       		res += s;
     	}
   	}
   	res = modl(res/2);

	
	
	/*-----------------------------*/
	return res;
}
