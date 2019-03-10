#include <iostream>
#define pi 3.14159

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


int modl(int);//Поиск модуля от int

double modl(double);//Поиск модуля от double

double testPoint(coord, coord, coord);

int testArr(double *);

int testFigure(figure);
