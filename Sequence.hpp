# pragma
# include<iostream>
# include<vector>
using namespace std;

class Sequence:public vector<int>
{
private:
    int m_score;
    int m_max;//min 固定是1
public:
    int getDiff(Sequence& );
    int getScore(Sequence& );
};
