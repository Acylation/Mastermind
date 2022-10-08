#include "Table.hpp"
using namespace std;

/*
public:
    // Construct
Table();//table1
Table(Table &);//table3
Table(vector<vector<int>> &);
Table(int rows, int cols);//table2
Table(int *p, int rows, int cols);
    Table(vector<int> &list, int rows, int cols); // List 2 Table
Table(vector<int> &seq, int cols);            // LinearSeq 2 Table
    ~Table();

// Basic
void Reset();//清空，回收Vec
void Clear();//置零，等价于BatchSet(0)
void Resize(int rows, int cols);//expand, narrow, (keep)
void BatchSet(int value); //所有元素设置成需要的值
void Print();
    vector<vector<int>> getTable();
int getRows();
int getCols();
int getCount(int target); //返回目标值的个数
int getSum();
    int getCountByRow(int target, int rowIndex);
    int getSumByRow(int rowIndex);
    int getCountByColumn(int target, int colIndex);
    int getSumByColume(int colIndex);

    // Converter
vector<int> Table2Seq();
    vector<int> Table2List();

    // Algos
    int Match(Table &standard); //返回命中数，使用 1*1=1，0*1=0 性质
    int Match(vector<int> &seq);

    // Operators
Table &operator=(const Table &ptable);//table1,table3
};
*/

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

void DisplayTableInfo(Table &table)
{
    cout
        << "--- Info Start ---" << endl;
    cout << "Rows: " << table.getRows() << endl;
    cout << "Cols: " << table.getCols() << endl;
    cout << "Sum: " << table.getSum() << endl;
    cout << "--- Info End ---" << endl
         << endl;
}

int main()
{
    Table table1;
    cout << "table1: " << endl;
    DisplayTableInfo(table1); // assertion: 0, 0, 0

    table1.Resize(3, 4);
    cout << "table1 after resize(3,4): " << endl;
    DisplayTableInfo(table1); // assertion: 3, 4, 0

    table1.BatchSet(2);
    cout << "table1 after batchset(2): " << endl;
    DisplayTableInfo(table1); // assertion: 3, 4, 24

    table1.Resize(4, 8); // expand
    cout << "table1 after resize(4,8): " << endl;
    DisplayTableInfo(table1);                                                         // assertion: 4, 8, 24
    cout << "the amount of elements(2) in table1 is: " << table1.getCount(2) << endl; // assertion: 12

    Table table2(4, 6);
    cout << "table2: " << endl;
    DisplayTableInfo(table2); // assertion: 4, 6, 0

    table2.BatchSet(3);
    cout << "table2 after batchset: " << endl;
    DisplayTableInfo(table2); // assertion: 4, 6, 72

    table2.Resize(3, 5); // narrow
    cout << "table2 after resize: " << endl;
    DisplayTableInfo(table2); // assertion: 3, 5, 45

    Table table3(table2);
    cout << "table3: " << endl;
    DisplayTableInfo(table3); // assertion: 3, 5, 45

    table2.Reset();
    cout << "table2 after reset: " << endl;
    DisplayTableInfo(table2); // assertion: 0, 0, 0

    table2.Print();
    // assertion
    /*
    --- Table Start ---
    --- Table End ---
    */

    table3.Clear();
    cout << "table3 after clear: " << endl;
    DisplayTableInfo(table3); // assertion: 3, 5, 0

    table3.Print();
    // assertion
    /*
    --- Table Start ---
    0, 0, 0, 0, 0
    0, 0, 0, 0, 0
    0, 0, 0, 0, 0
    --- Table End ---
    */

    table3 = table1;
    cout << "table3 after assign: " << endl;
    DisplayTableInfo(table3); // assertion: 4, 8, 24

    table3.Print();
    // assertion:
    /*
    --- Table Start ---
    2, 2, 2, 2, 0, 0, 0, 0
    2, 2, 2, 2, 0, 0, 0, 0
    2, 2, 2, 2, 0, 0, 0, 0
    0, 0, 0, 0, 0, 0, 0, 0
    --- Table End ---
    */
    
    vector<int> seq1{1,2,2,1,2,2,4,4,4,3};
    vector<vector<int>> vvtable
    {
        {1,0,0,0},
        {0,1,0,0},
        {0,1,0,0},
        {1,0,0,0},
        {0,1,0,0},
        {0,1,0,0},
        {0,0,0,1},
        {0,0,0,1},
        {0,0,0,1},
        {0,0,1,0}
    };
    int aatable[10][4] =
    {
        {1,0,0,0},
        {0,1,0,0},
        {0,1,0,0},
        {1,0,0,0},
        {0,1,0,0},
        {0,1,0,0},
        {0,0,0,1},
        {0,0,0,1},
        {0,0,0,1},
        {0,0,1,0}
    };

    Table table4(seq1,4);
    cout << "table4: " << endl;
    DisplayTableInfo(table4); // assertion: 10, 4, 10

    Table table5(vvtable);
    cout << "table5: " << endl;
    DisplayTableInfo(table5); // assertion: 10, 4, 10

    Table table6((int *)aatable, 10, 4);
    cout << "table6: " << endl;
    DisplayTableInfo(table6); // assertion: 10, 4, 10

    table1.Reset();
    vector<int> seq2 = table1.Table2Seq();
    Table table7(seq2, 4);
    cout << "table7: " << endl;
    DisplayTableInfo(table7); // assertion: 0, 4, 0
    
    return 0;
}

/*
int main()
{

    cout<<"the score is: "<<table1.Match(table2)<<endl;
    cout<<"the sum is: "<<table1.getSum()<<endl;
    cout<<"the count of '1' is: "<<table1.getCount(1)<<endl;

    PrintVec(table2.Table2List(),'[',',',']');
    PrintVec(table2.Table2Seq(),'[',',',']');
    vector<int> table2seq = table2.Table2Seq();
    cout<<"the score is: "<<table1.Match(table2seq)<<endl;

    Table table3(p,1,20);
    table3.Print();
}
*/