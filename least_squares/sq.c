#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class LR
{
	double a, b;
public:
	LR(const vector<double>&x, const vector<double>&y)
	{
		double t1,t2,t3,t4;
		for(int i = 0; i<x.size(); i++)
		{
			t1 += x[i]*x[i];
			t2 += x[i];
			t3 += x[i]*y[i];
			t4 += y[i];
		}
		a = (t3*x.size() - t2*t4) / (t1*x.size() - t2*t2);
		b = (t1*t4 - t2*t3) / (t1*x.size() - t2*t2);
	}
	
	double getY(const double x) const
	{
		return a*x + b;
	}

	void print() const
	{
		cout << "y =" << a << "x + " << b << endl;
	}
};

int main(int argc, char * argv[])
{
	if(argc != 2)
	{
		cout << "Usage: DataFile.txt" << endl;
		return -1;
	}
	else
	{
		vector<double>x;
		ifstream in(argv[1]);
		for(double d; in>>d; )
		{ x.push_back(d);}
		int sz = x.size();
		vector<double>y(x.begin() + sz/2, x.end());
		x.resize(sz/2);
		LR lr(x, y);
		lr.print();

		cout << "pls input x:" << endl;
		double x0;
		while(cin >> x0)
		{
			cout << "y =" << lr.getY(x0) << endl;
			cout << "pls input x:" << endl;
		}
	}
}
