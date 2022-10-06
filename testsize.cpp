#include<iostream>
#include<ctime>

using namespace std;
int main()
{
    cout<<"size of long is:"<<sizeof(long)<<endl;
    cout<<"size of float is:"<<sizeof(float)<<endl;
    cout<<"size of string is:"<<sizeof(string)<<endl;
    cout<<"size of time is: "<<sizeof(time(0))<<endl;
    cout<<"size of int64 is: "<<sizeof(int64_t)<<endl;
    return 0 ;
}