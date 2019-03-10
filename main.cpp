#include "funcshen.hpp"

using namespace std;



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
