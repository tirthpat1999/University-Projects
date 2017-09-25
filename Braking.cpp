#include <iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main( const int argc, const char* const argv[])
{
	float velocity= atof(argv[1]);
    float distance= atof(argv[2]);
    float minDeceleration= (-pow(velocity, 2)/(2*distance));
    float stoppingTime= (-velocity/minDeceleration);
    cout << "Initial car velocity: " << velocity << "m/s" << endl;
    cout << "Distance to obstacle: " << distance << "m" << endl;
    cout << "Minimum deceleration: " << minDeceleration << "m/s/s" << endl;
    cout << "Maximum stopping time: " << stoppingTime << "s" << endl;
      

}