#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Randomize()
{
	srand( (int)time(NULL) );
}

int GenerateRandomNumber( int low, int high )
{
	double _d;
	if( low > high )
	{
		cout << "GenerateRandomNumber: Make sure low <= high.\n";
		exit( 1 );
	}
	_d = (double)rand() / ((double)RAND_MAX + 1.0);
	return (low + (int)(_d * (high - low + 1)));
}

double GenerateRandomReal( double low, double high )
{
	double _d;
	if( low > high )
	{
		cout << "GenerateRandomReal: Make sure low <= high.\n";
		exit( 2 );
	}
	_d = (double)rand() / (double)RAND_MAX;
	return (low + _d * (high - low));
}
