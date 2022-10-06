#include <ctime>
#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
    
    FILETIME testFtime;//8 Bytes
    SYSTEMTIME testStime;
    testFtime.dwHighDateTime = 0x01CC2437;//4 Bytes
    testFtime.dwLowDateTime = 0x44B9B848;
    FileTimeToSystemTime(&testFtime, &testStime);
    //2011.06.06 10:48:28    
    cout<<"The input utctime is:"
    << testStime.wYear << " " 
    << testStime.wMonth << " " 
    << testStime.wDay << " " 
    << testStime.wHour << " "
    << testStime.wMinute << " "
    << testStime.wSecond << " "
    <<endl;
    return 0;

    //cin >> hex >> x //10进制转16进制  输入输出进制转换 iomanip 库
}