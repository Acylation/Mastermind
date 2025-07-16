#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <random>
#include <ctime>
#include <windows.h>
using namespace std;
using namespace std;


//必须加static，Ref: https://blog.csdn.net/CSDNwei/article/details/113865349

//Universal Functions
inline int RandInt(int start, int end)//仿 Casio 991CNX
{
    static default_random_engine e(time(0));
    static uniform_int_distribution<int> uniInt(start, end);
    Sleep(1000); // windows.h 库函数
    return uniInt(e);
}

void PrintVec(vector<int> vtemp, const char prefix, const char seperator, const char suffix)
{
    int n = vtemp.size();
    cout << prefix;
    for (int i = 0; i < n - 1; i++)
    {
        cout << vtemp.at(i) << seperator;
    }
    cout << vtemp.at(n - 1) << suffix << endl;
}

void ExportVec(vector<int> vtemp)
{
    //export to .csv, seperated by endl
}

vector<int> Generator(int count)
{
    vector<int> vtemp;
    for (int i = 0; i < count; i++)
    {
        vtemp.push_back(RandInt(1, 4));
    }
    return vtemp;
}

class Quiz
{
private:
    vector<int> m_solusion;
    int m_count;

public:
    Quiz(int count) { m_count = count; }
    void Generate() 
    { 
        cout<<"Generating..."<<endl;
        m_solusion = Generator(m_count);
    }
    void PrintAnswer() { PrintVec(m_solusion,'[' , ',' , ']'); }//example: [2,4,1,4,3,3,1,3,4,1]
    void Stat()
    {
        int n = m_count;
        vector<int> counter(4,0);
        for (int i = 0; i < n; i++)
            counter.at(m_solusion.at(i)-1) += 1;//妙哉妙哉，这里抽象一个StatVec函数，就是把“4”参数化
        cout<<"stat: ";
        PrintVec(counter,'\0',',','\0');//example: 3,1,3,3
    }
    ~Quiz() {}
};

class AnswerSheet
{
private:
    vector<int> m_answer;
public:
    AnswerSheet()
    {

    }
    ~AnswerSheet();
};

AnswerSheet::~AnswerSheet()
{
}



int main()
{
    Quiz qtest(10);
    qtest.Generate();
    qtest.PrintAnswer();
    qtest.Stat();
    return 0;
}


//Quiz函数出题，这个类可以泛化，因为生成的都是VectorInt，例如，叫做Generator
//AnswerSheet仅记录答案，vector<AnswerSheet>用来做操作
//评分函数给在AnswerSheet里，分数记在AnswerSheet上
//答案列表和选项矩阵互相转换，便于形象化思考
//选项重排
//策略模块

//手动单元测试
//随机性验证 1.大量随机是否均匀，2.随机自相关、与期望分布的差距，3.多次运行程序，随机相关性