#pragma once
#include <random>
#include <iostream>
using namespace std;

//Universal Functions
inline int RandInt(int start, int end)//仿 Casio 991CNX
{
    random_device rd;
    //mingw偷懒 https://zhuanlan.zhihu.com/p/537101533
    static default_random_engine e(rd);
    static uniform_int_distribution<int> uniInt(start, end);
    //必须加static
    //Ref: https://blog.csdn.net/CSDNwei/article/details/113865349
    return uniInt(e);
}

random_device srand()
{
    random_device rd;
    return rd;
}