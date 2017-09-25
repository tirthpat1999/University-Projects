#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
using namespace std;


int main( const int argc, const char* const argv[])
{
    if (argc<=3)
        cerr << "Error: Unable to compute statistics over data set because data was not entered." << endl;    
    
    if(atof(argv[2])<0)
        cerr << "Error: Unable to compute statistics over data set because age limit is negative." << endl;
    
    if(atof(argv[1])>=1||argv[1]<=0)
        cerr <<"Error: Unable to compute statistics over data set because weighting parameter  be between 0 and 1." << endl;    
    
    float minNum=atof(argv[3]);
    float maxNum=0;
    int x=3;
    float weight= atof(argv[1]);   
    float EWMA= atof(argv[3]);
    cout << "Sample    Value   Minimum  EWMA  Maximum" << endl;
    int minAge=0;
    int maxAge=0;
    int ageLimit=atoi(argv[2]);
    
    while(x<=argc-1)
    
    {
        float current=atof(argv[x]);
        if (current<minNum)
        {
            minNum=current;
            minAge=0;
        }
        else
        {
            minAge++;
        }
        if (current>maxNum)
        {
            maxNum=current;
            maxAge=0;
        }
        else 
            maxAge++;
        if(minAge>ageLimit)
        {
            int y=1;
            minNum=current;
            while(y<ageLimit)
            {
                if (atof(argv[x-y])<minNum)
                {
                    minNum=(atof(argv[x-y]));
                }                    
                y++;
            }
            minAge=0;                      
        }
        
        if (maxAge>ageLimit)
        {
            int y=1;
            maxNum=current;
            while(y<ageLimit)
            {
                if (atof(argv[x-y])>maxNum)
                {
                    maxNum=(atof(argv[x-y]));
                }
                                
                y++;
            }
            maxAge=0;
        }                    
        
        EWMA=current*weight+(1-weight)*EWMA;
        cout << x-2 << "         " << current<< "       " << minNum << "      " << EWMA<< "     " << maxNum << endl;        
        x++;
    }
    
}