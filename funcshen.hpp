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
	private:
		double x[4], y[4];
	public:
		coord mCoord[4];
		figure(double x0=0.0, double y0=0.0, double x1=0.0, double y1=0.0, double x2=0.0, double y2=0.0, double x3=0.0, double y3=0.0)
		{
			x[0] = x0, y[0] = y0, x[1] = x1, y[1] = y1, x[2] = x2, y[2] = y2, x[3] = x3, y[3] = y3;
			for(int i = 0; i < 4; i++)
			{
				mCoord[i].x = x[i];
				mCoord[i].y = y[i];
			}
		}
		void init(double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3)
		{
			x[0] = x0, y[0] = y0, x[1] = x1, y[1] = y1, x[2] = x2, y[2] = y2, x[3] = x3, y[3] = y3;
			for(int i = 0; i < 4; i++)
			{
				mCoord[i].x = x[i];
				mCoord[i].y = y[i];
			}
			return;
		}
};


int modl(int);//Поиск модуля от int

double modl(double);//Поиск модуля от double

double testPoint(coord, coord, coord);

int testArr(double *);

int testFigure(figure);

double square(figure);
