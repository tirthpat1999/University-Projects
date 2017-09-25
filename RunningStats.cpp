#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
using namespace std;


int main( const int argc, const char* const argv[])
{
    if (argc<2)
        cerr << "Unable to compute statistics over data set because data was not entered" << endl;
   
    
    float minNum=atof(argv[1]);
    float maxNum=0;
    int x=1;
    float sum=0;
    float average;
    cout << "Sample    Value   Minimum  Average  Maximum" << endl;
    while(x<=argc-1)
    {
        float current=atof(argv[x]);
        if (current<minNum)
        {
            minNum=current;
        }
        if (current>maxNum)
        {
            maxNum=current;
        }        
        sum+=current;
        average=sum/x;
        cout << x << "    " << current<< "   " << minNum << "  " << average<< "  " << maxNum << endl;
        x++;
    }
    
               
    
}