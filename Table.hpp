//# pragma once
#include <iostream>
#include <vector>
using namespace std;

class Table
{
private:
    vector<vector<int>> m_table;
    int m_rows;
    int m_cols;

public:
    // Construct
    Table();
    Table(int rows, int cols);
    Table(Table &);
    Table(vector<vector<int>> &);
    Table(int *p, int rows, int cols);
    Table(vector<int> &list, int rows, int cols); // List 2 Table
    Table(vector<int> &seq, int cols);            // LinearSeq 2 Table
    ~Table();

    // Basic
    void Reset(); //清空，回收Vec
    void Clear(); //置零，等价于BatchSet(0)
    void Resize(int rows, int cols);
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
    // void deleteEmptyRow();
    // void deleteEmptyColumn();

    // Converter
    vector<int> Table2Seq();
    vector<int> Table2List();

    // Algos
    int Match(Table &standard); //返回命中数，使用 1*1=1，0*1=0 性质
    int Match(vector<int> &seq);

    // Operators
    Table &operator=(const Table &ptable);
};

Table::Table()
{
    m_rows = 0;
    m_cols = 0;
}

Table::Table(int rows, int cols)
{
    m_rows = rows;
    m_cols = cols;
    vector<vector<int>> vtemp(rows, vector<int>(cols));
    m_table = vtemp;
}

Table::Table(Table &table)
{
    m_rows = table.m_rows;
    m_cols = table.m_cols;
    m_table = table.m_table;
}

Table::Table(vector<vector<int>> &p_table)
{
    m_rows = p_table.size();
    m_cols = p_table.at(0).size();
    m_table = p_table;
}

Table::Table(int *p, int rows, int cols) //待测试
{
    m_rows = rows;
    m_cols = cols;
    vector<int> row(cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            row.at(j) = p[i * cols + j];
        m_table.push_back(row);
    }
}

Table::Table(vector<int> &list, int rows, int cols)
{
    m_rows = rows;
    m_cols = cols;
    vector<vector<int>> vtemp(rows, vector<int>(cols));
    m_table = vtemp;

    int size = list.size();
    if (rows * cols < size)
    {
        cout << "Warning: "
             << "Vector out of range, some elements will be abandoned." << endl;
        size = rows * cols;
    }
    for (int i = 0; i < size; i++)
        m_table.at(i / cols).at(i % cols) = list.at(i);
}

Table::Table(vector<int> &seq, int cols) // seq采用自然顺序，如1,2,3,4，区别于数组下标从0开始
{
    int rows = seq.size();
    m_rows = rows;
    m_cols = cols;
    vector<vector<int>> vtemp(rows, vector<int>(cols));
    m_table = vtemp;
    /*
    //Resize 写法和先建立后赋值哪个好些？
    m_table.resize(rows);
    for (int i = 0; i < rows; i++)
        m_table.at(i).resize(cols);
    */
    for (int i = 0; i < rows; i++)
        m_table.at(i).at(seq.at(i) - 1) = 1;
}

Table::~Table()
{
}

void Table::Reset()
{
    m_rows = 0;
    m_cols = 0;
    vector<vector<int>> vtemp;
    m_table.swap(vtemp);
}

void Table::Clear()
{
    for (int i = 0; i < m_rows; i++)
        for (int j = 0; j < m_cols; j++)
            m_table.at(i).at(j) = 0;
}

void Table::Resize(int rows, int cols)
{
    if (rows < m_rows || cols < m_cols)
    {
        cout << "Warning: "
             << "New size is too small, some elements will be abandoned." << endl;
    }
    m_table.resize(rows);
    for (int i = 0; i < rows; i++)
        m_table.at(i).resize(cols);
    m_rows = rows;
    m_cols = cols;
}

void Table::BatchSet(int value)
{
    for (int i = 0; i < m_rows; i++)
        for (int j = 0; j < m_cols; j++)
            m_table.at(i).at(j) = value;
}

void Table::Print()
{
    cout
        << "--- Table Start ---" << endl;
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols - 1; j++)
            cout << m_table.at(i).at(j) << ",";
        cout << m_table.at(i).at(m_cols - 1) << endl;
    }
    cout << "--- Table End ---" << endl
         << endl;
}

vector<vector<int>> Table::getTable()
{
    return m_table;
}

int Table::getRows()
{
    return m_rows;
}

int Table::getCols()
{
    return m_cols;
}

int Table::getCount(int target)
{
    int count = 0;
    for (int i = 0; i < m_rows; i++)
        for (int j = 0; j < m_cols; j++)
            if (m_table.at(i).at(j) == target)
                count++;
    return count;
}

int Table::getSum()
{
    int sum = 0;
    for (int i = 0; i < m_rows; i++)
        for (int j = 0; j < m_cols; j++)
            sum += m_table.at(i).at(j);
    return sum;
}

int Table::getCountByRow(int target, int rowIndex)
{
    int count = 0;
    for (int i = 0; i < m_cols; i++)
        if (m_table.at(rowIndex).at(i) == target)
            count++;
    return count;
}

int Table::getSumByRow(int rowIndex)
{
    int sum = 0;
    for (int i = 0; i < m_cols; i++)
        sum += m_table.at(rowIndex).at(i);
    return sum;
}

int Table::getCountByColumn(int target, int colIndex)
{
    int count = 0;
    for (int i = 0; i < m_rows; i++)
        if (m_table.at(i).at(colIndex) == target)
            count++;
    return count;
}

int Table::getSumByColume(int colIndex)
{
    int sum = 0;
    for (int i = 0; i < m_rows; i++)
        sum += m_table.at(colIndex).at(i);
    return sum;
}

vector<int> Table::Table2Seq() //暂时先只支持0，1二值表格
{
    vector<int> vseq(m_rows);
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            if (m_table.at(i).at(j) == 1)
                vseq.at(i) = j + 1; //转化为自然序列
        }
        if (getCountByRow(1, i) != 1)
            cout << "Error: wrong dataset in row" << i << endl;
    }
    return vseq;
}

vector<int> Table::Table2List()
{
    vector<int> vlist(m_rows * m_cols);
    for (int i = 0; i < m_rows; i++)
        for (int j = 0; j < m_cols; j++)
            vlist.at(i * m_cols + j) = m_table.at(i).at(j);
    return vlist;
}

int Table::Match(Table &standard)
{
    int score = 0;
    for (int i = 0; i < m_rows; i++)
        for (int j = 0; j < m_cols; j++)
            if (m_table.at(i).at(j) * standard.m_table.at(i).at(j) == 1) // 01二值表
                score++;
    return score;
}

int Table::Match(vector<int> &seq)
{
    int score = 0;
    for (int i = 0; i < m_rows; i++)
        if (m_table.at(i).at(seq.at(i) - 1) == 1)
            score++;
    return score;
}

Table &Table::operator=(const Table &ptable)
{
    m_rows = ptable.m_rows;
    m_cols = ptable.m_cols;
    m_table = ptable.m_table;
    return *this;
}
