// C++ 作业，矩阵类的实现
// author: Haoyu Chen @ HDU-PHOENIX
// 2024.11.30
//
// 1. 完善矩阵类的实现，每正确实现一个函数 3 分，共 99 分；
// 2. 函数实现在 Matrix.cpp 文件中，0.5 分；
// 3. 正确编写 CMakelists.txt 文件，0.5 分。
//
// 附加题：对于每个函数，是否进行了异常处理，共 20 分，单独计分。
//
// 无法实现的功能，注释掉声明以及 main.cpp 中的调用。
// setMatrix() 函数用于设置矩阵，任选一种方式即可；
//              若都未实现，请自行添补遍历赋值。
// printMatrix() 函数用于输出矩阵，任选一种方式即可；
//               若都未实现，请自行添补遍历输出。
// main() 中的矩阵大小和数据均可修改。
// main.cpp 和 Matrix.hpp，除以上情况外不可修改。
//
// ps: 不要骗分哦～

#include <iostream>
#include <math.h>

#include "./include/Matrix.hpp"

Matrix::Matrix()
{
    data = NULL;
}
Matrix::Matrix(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    data = new double* [rows];
    for (int i = 0; i < rows ; ++i)
    {
        data[i] = new double[cols];
    }
}
Matrix& Matrix::set(int row, int col, double value)
{
    data[row - 1][col - 1] = value;
    return *this;
}
    
int Matrix::getRows() const
{
    return rows;
}

int Matrix::getCols() const
{
    return cols;
}

void setMatrix(Matrix &matrix, double *values)
{
    // set 函数
    // matrix.set(1, 1, values[0]).set(1, 2, values[1])
    //       .set(2, 1, values[2]).set(2, 2, values[3]);
    
    // 重载运算符 <<，实现矩阵的输入
    for (int i = 0; i < matrix.getRows() * matrix.getCols(); ++i)
    {
        matrix << values[i];
    }
}

Matrix & Matrix::operator<<(double value)
{
    static int x = 0;
    static int y = 0;
    if (y >= cols)
    {
        ++x;
        y = 0;
    }
    if (x >= rows)
    {
        x = 0;
    }
    data[x][y++] = value; 
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix)
{
    for (int i = 0; i < matrix.rows ; ++i)
    {
        for (int j = 0 ; j < matrix.cols ; ++j)
        {
            os << matrix.data[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}


void printMatrix(const Matrix &matrix)
{
    // print 函数
    // matrix.print();

    // 重载流运算符 <<，实现矩阵的输出
    std::cout << matrix;

    // 重载运算符 ()，实现矩阵的访问
    // std::cout << matrix(1, 1) << matrix(1, 2) << std::endl
    //           << matrix(2, 1) << matrix(2, 2) << std::endl;
}

const Matrix& Matrix::print() const
{
    for (int i = 0; i < rows ; ++i)
    {
        for (int j = 0 ; j < cols ; ++j)
        {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return *this;
}

double Matrix::operator()(int row, int col) const
{
    return data[row][col];
}

double Matrix::get(int row, int col) const
{
    return data[row][col];
}

Matrix Matrix::operator+(const Matrix &other) const
{
    if (! samesize(other))
    {
        throw std::runtime_error("diff size");
    }
    Matrix m(this->rows, this->cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            m.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return m;
}

Matrix Matrix::operator-(const Matrix &other) const
{
    if (! samesize(other))
    {
        throw std::runtime_error("diff size");
    }
    Matrix m(this->rows, this->cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            m.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return m;
}

Matrix Matrix::operator-() const
{
    Matrix m(this->rows, this->cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            m.data[i][j] = -data[i][j];
        }
    }
    return m;
}

Matrix Matrix::operator*(const Matrix &other) const
{
    if (cols != other.rows)
    {
        throw std::runtime_error("can't muilty");
    }
    Matrix m(this->rows, other.cols);
    for (int i = 0; i < this->rows; ++i)
    {
        for (int j = 0; j < other.cols ; ++j)
        {
            for (int k = 0; k < cols ; ++k)
            {
                m.data[i][j] = data[i][k] * other.data[k][j];
            }
        }
    }
    return m;
}

Matrix & Matrix::operator=(const Matrix &other)
{
    if (data == NULL)
    {
        rows = other.rows;
        cols = other.cols;
        data = new double *[rows];
        for (int i = 0; i < rows ; ++i)
        {
            data[i] = new double[cols];
        }
        for (int i= 0; i < rows ; ++i)
        {
            for (int j = 0; j < cols ; ++j)
            {
                data[i][j] = other.data[i][j];
            }
        }
    }
    else
    {
        if (! samesize(other))
        {
            throw std::runtime_error("diff size");
        }
        for (int i = 0; i < rows ; ++i)
        {
            for (int j = 0; j < cols ;++j)
            {
                data[i][j] = other.data[i][j];
            }
        }
    }
    return *this;
}

Matrix & Matrix::operator=(Matrix &&other)
{
    *this = other;
    other.~Matrix();
    return *this;
}

Matrix:: Matrix(const Matrix &other)
{
    data = NULL;
    *this = other;
}

Matrix:: Matrix(Matrix &&other)
{
    *this = other;
    other.~Matrix();
}

Matrix:: ~Matrix()
{
    for (int i = 0; i < rows ; ++i)
    {
        delete[] data[i];
    }
    delete[] data;
}

Matrix Matrix::operator/(const Matrix &other) const
{
    Matrix m = other.inverse() * *this;
    return m;
}


bool Matrix::operator==(const Matrix &other) const
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols ; ++j)
        {
            if (data[i][j] != other.data[i][j])
            {
                return false;
            }
        }
    }
    return true;
}


bool Matrix::operator!=(const Matrix &other) const
{
    if (! samesize(other))
    {
        return true;
    }
    else
    {
        if (! (*this == other))
        {
            return true;
        }
    }
    return false;
}

bool Matrix::samesize(const Matrix &other) const
{
    if (other.rows == rows && other.cols == cols)
    {
        return true;
    }
    return false;
}

Matrix Matrix::transpose() const
{
    Matrix m(cols, rows);
    for (int i = 0; i < rows ;++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            m.data[j][i] = data[i][j];
        }
    }
    return m;
}

bool Matrix::isSquare() const
{
    return (rows == cols);
}

int Matrix::search_first_not_zero_row(int cols) const
{
    for (int i = 0; i < rows ; ++i)
    {
        if (data[cols][i] != 0)
        {
            return i;
        }
    }
    return -1;
}

void Matrix::swap_rows(int row1, int row2)
{
    double *temp = data[row1];
    data[row1] = data[row2];
    data[row2] = temp;
}

void Matrix::transform_to_R(int limit_rows, int limit_cols)
{
    for (int j = 0; j < limit_cols ; ++j)
    {
        int first_row = search_first_not_zero_row(j);
        if (first_row == -1)
        {
            continue;
        }
        swap_rows(first_row, j);
        double main_num = data[j][j];
        for (int l = 0; l < cols ; ++l)
        {
            data[j][l] /= main_num;
        }
        for (int i = j + 1; i < limit_rows ; ++i)
        {
            double time_num = data[i][j];
            for (int k = j; k < cols ; ++k)
            {
                data[i][k] -= time_num * data[j][k];
            }
        }
    }
    // print();
}

int Matrix::search_first_not_zero_column(int row) const 
{
    for (int j = 0; j < cols ; ++j) 
    {
        if (data[row][j] != 0) 
        {
            return j;
        }
    }
    return -1;
}
void Matrix::swap_columns(int col1, int col2) 
{
    for (int i = 0; i < rows ; ++i) 
    {
        std::swap(data[i][col1], data[i][col2]);
    }
}

double Matrix::determinant() const
{
    if (! this->isSquare())
    {
        throw std::runtime_error("not square");
    }
    Matrix m(*this);
    for (int j = 0; j < cols ; ++j)
    {
        int first_row = m.search_first_not_zero_row(j);
        if (first_row == -1)
        {
            return 0;
        }
        m.swap_rows(first_row, j);
        double main_num = m.data[j][j];
        for (int i = j + 1; i < rows ; ++i)
        {
            double time_num = m.data[i][j];
            if (time_num != 0)
            {
                time_num /= main_num;
            }
            for (int k = j; k < cols ; ++k)
            {
                m.data[i][k] -= time_num * m.data[j][k];
            }
        }
    }
    // std::cout << std::endl; //调试代码。
    // printMatrix(m);
    double determinant = 1.0;
    for (int k = 0; k < rows ; ++k)
    {
        determinant *= m.data[k][k];
    }
    return determinant;
}

void Matrix::transform_to_I()
{
    if (! isSquare())
    {
        throw std::runtime_error("not square");
    }
    for (int i = 0; i < rows ; ++i)
    {
        for (int j = 0; j < cols ;++j)
        {
            if (i != j)
            {
                data[i][j] = 0.0;
            }
            else
            {
                data[i][j] = 1.0;
            }
        }
    }
}

Matrix Matrix::link_matrix(Matrix &other)
{
    if (rows != other.rows)
    {
        throw std::runtime_error("can't link");
    }
    Matrix m(rows, cols + other.cols);
    for (int i = 0; i < rows ; ++i)
    {
        for (int j = 0; j < m.cols ; ++j)
        {
            if (j < cols)
            {
                m.data[i][j] = data[i][j];
            }
            else
            {
                m.data[i][j] = other.data[i][j - cols];
            }
        }
    }
    return m;
}

void Matrix::backward(int limit_rows, int limit_cols)
{
    for (int i = limit_rows - 1; i > 0 ; --i)
    {
        for (int j = i - 1; j >= 0 ; --j)
        {
            double main_num = data[j][i];
            for (int k = limit_cols ; k < cols ; ++k)
            {
                data[j][k] -= main_num * data[i][k];
            }
            data[j][i] = 0;
        }
    }
}

Matrix Matrix::inverse() const
{
    if (fabs(determinant()) < 1e-2)
    {
        throw std::runtime_error("determinant = 0");
    }
    Matrix I(rows, cols);
    I.transform_to_I();
    Matrix p = *this;
    Matrix q = p.link_matrix(I);
    q.transform_to_R(rows, cols);
    q.backward(rows, cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols ; ++j)
        {
            I.data[i][j] = q.data[i][j + cols];
        }
    }
    return I;
}

int main()
{
    try
    {        
        Matrix m(3, 3);
        double test1[9] { 1, 2, -1, 3, 4, -2, 5, -4, 1};
        setMatrix(m, test1);
        // m << 5 << 2 << 0 << 0 << 2 << 1 << 0 << 0 << 0 << 0 << 8 << 3 << 0 << 0 << 5 << 2; 
        std::cout << m;
        printMatrix(m);

        Matrix n(3, 3);
        double test2[9] {0, 0, 0.2, 2, 1, 0, 4, 3, 0};
        setMatrix(n, test2);
        std::cout << n;
        printMatrix(n);

        std::cout << m + n << std::endl;
        printMatrix(m + n);

        std::cout << m - n << std::endl;
        printMatrix(m - n);

        std::cout << m * n << std::endl;
        printMatrix(m * n);

        std::cout << m / n << std::endl;
        printMatrix(m / n);

        Matrix temp = m;
        std::cout << m << std::endl;
        printMatrix(temp);

        std::cout << -m << std::endl;
        printMatrix(-m);

        std::cout << "m^T" << std::endl;
        printMatrix(m.transpose());

        // Matrix o(2, 2);
        // o.transform_to_I();
        // printMatrix(o);

        // Matrix p = m.link_matrix(o);
        // printMatrix(p);

        std::cout << "m^-1" << std::endl;
        printMatrix(m.inverse());

        std::cout << (m == n) << ":"  << (m == n) << std::endl;
        std::cout << (m != n) << ":" << (m != n) << std::endl;

        std::cout << "|m|: " << m.determinant() << std::endl;
        // p.transform_to_R(m.getRows(), m.getCols());
        // p.backward(m.getRows(), m.getCols());
        // printMatrix(p);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}