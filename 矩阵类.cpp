# include <iostream>

# include <vector>

using namespace std;

class Mat
{
public:
    int row, col;
    vector<vector<int>> mat; 
    Mat(int row, int col) : row(row), col(col)
    {
        mat.resize(row);
        for (int i = 0; i < row ; ++i)
        {
            mat[i].resize(col);
        }
    };
    friend ostream& operator<<(ostream& cout, const Mat& m);
    friend istream& operator>>(istream& cin, Mat& m);
    friend Mat operator+(Mat& m1, Mat& m2);
    friend Mat operator-(Mat& m1, Mat& m2);
    friend Mat operator*(Mat& m1, Mat& m2);
};

ostream& operator<<(ostream& cout, const Mat& m)
{
    for (auto it = m.mat.begin(); it!= m.mat.end(); ++it)
    {
        for (auto in_it = it->begin(); in_it!= it->end(); ++in_it)
        {
            cout << *in_it << " ";
        }
        cout << endl;
    }
    return cout;
}
istream& operator>>(istream& cin, Mat& m)
{
    cout << "输入矩阵" << m.row << " " << m.col << endl;
    for (int i = 0; i < m.row; ++i)
    {
        for (int j = 0; j < m.col; ++j)
        {
            cin >> m.mat[i][j];
        }
    }
    cout << endl;
    return cin;
}
Mat operator+(Mat& m1, Mat& m2)
{   
    Mat m(m1.row, m1.col);
    if (m1.row != m2.row || m1.col != m2.col)
    {
        cout << "errow" << endl;
    }
    else
    {

        for (int i = 0; i < m1.row ; ++i)
        {
            for (int j = 0; j < m2.col ; ++j)
            {
                m.mat[i][j] = m1.mat[i][j] + m2.mat[i][j];
            }
        }
    }
    return m;
}
Mat operator-(Mat& m1, Mat& m2)
{   
    Mat m(m1.row, m1.col);
    if (m1.row != m2.row || m1.col != m2.col)
    {
        cout << "errow" << endl;
    }
    else
    {

        for (int i = 0; i < m1.row ; ++i)
        {
            for (int j = 0; j < m2.col ; ++j)
            {
                m.mat[i][j] = m1.mat[i][j] - m2.mat[i][j];
            }
        }
    }
    return m;
}
Mat operator*(Mat& m1, Mat& m2)
{
    Mat m(m1.row, m2.col);
    if (m1.col != m2.row)
    {
        cout << "errow" << endl;
    }
    else
    {
        for (int i = 0; i < m1.row ; ++i)
        {
            for (int j = 0 ; j < m2.col ; ++j)
            {
                for (int k = 0; k < m1.col ; ++k)
                {
                    m.mat[i][j] += m1.mat[i][k] * m2.mat[k][j];
                }
            }
        }
    }
    return m;
}

int main()
{
    // Mat m1(2, 2), m2(2, 2), m3(2, 2), m4(2, 2), m5(2, 2);
    // cin >> m1 >> m2;
    // cout << m1 << endl << m2 << endl;
    // m3 = m1 + m2;
    // m4 = m1 - m2;
    // m5 = m1 * m2;
    // cout << m3 << endl << m4 << endl << m5 << endl;
    Mat m1(3, 3), m2(3, 1), m(3, 1);
    cin >> m1 >> m2;
    m = m1 * m2;
    cout << m << endl;
    return 0;
}