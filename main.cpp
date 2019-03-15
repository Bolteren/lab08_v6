#include "funcshen.hpp"

using namespace std;

int main(void) 
{
	figure f1(1,1, 8,2, 7,5, 2,5), f2;
	
	f2.init(2,2, 8,1, 5,2, 7,4);
	cout << square(f1) << "\t" <<square(f2) << endl;
	return 0;
}
