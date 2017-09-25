#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;


int main( const int argc, const char* const argv[])
{
    if (argc<2)
        cerr << "Unable to compute statistics over data set because data was not entered" << endl;
    
    float num= argc-1;
    float minNum=atof(argv[1]);
    float maxNum=0;
    int x=1;
    float sum=0;
    
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
        
        x++;
    }
    float average=sum/num;
    cout << "Number of floating-point numbers: " << num << endl;
    cout << "Minimum floating-point number: " << minNum << endl;
    cout << "Average floating-point number: " << average << endl;
    cout << "Maximum floating-point number: " << maxNum << endl;
               
    
}