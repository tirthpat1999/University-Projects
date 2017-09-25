#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cmath>
using namespace std;


int main( const int argc, const char* const argv[])
{
    
    if (argc<4)
        cerr <<"Error: Insufficient arguements; expected three command-line arguments, velocity of car, distance to the obstacle and maximum deceleration" << endl;
    else if(argc>4)
        cerr << "Error: Too many arguements; expected three, recieved " << (argc-1) << "Ignoring extraneous arguments." << endl;
    else 
    {
        float velocity= atof(argv[1]);
        float distance= atof(argv[2]);
        float maxDeceleration= atof(argv[3]);
        
        if ((distance<0 && velocity>0) || (distance>0 && velocity<0))
            cout << "There is no possibility of collision because the car is traveling away from the obstacle" << endl;
        else if(velocity==0 && distance!=0)
            cout << "There is no possibility of collision because the car is not moving" << endl;
        else
        {
            float minDeceleration= (pow(velocity, 2)/(2*abs(distance)));
            float stoppingTime= abs(velocity)/abs(minDeceleration);
            if (abs(minDeceleration) <= abs(maxDeceleration))
            {
                cout << "Initial car velocity: " << velocity << "m/s" << endl;  
                cout << "Distance to obstacle: " << distance << "m/s" << endl;
                cout << "Minimum deceleration: " << minDeceleration << "m/s/s" << endl;           
                cout << "Maximum stopping time: " << stoppingTime << "s" << endl;

            }
            else
            {   
                distance= abs(distance);
                velocity= abs(velocity);

                float velocityFinal= sqrt((pow(velocity,2)-(2*abs(maxDeceleration)*distance)));
                stoppingTime= ((velocity-abs(velocityFinal))/abs(maxDeceleration));

                cout << "Crash will occur in " << stoppingTime << " seconds at velocity " << velocityFinal << "m/s; deploying airbags." << endl;
            }
        }
    }
        

}