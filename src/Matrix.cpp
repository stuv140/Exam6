
#include <iostream>
#include <cassert>
#include <tuple>
#include<memory> 
#include"Matrix.h"

int main()
{
    Matrix<int, -1> matrix;
    assert(matrix.Size() == 0);
    auto a = matrix[0][0];
    assert(a == -1);
    assert(matrix.Size() == 0);
    matrix[100][100] = 314; //Опционально реализовать каноническую форму оператора =
    assert(matrix.Size() == 1);
    for (auto c : matrix)
    {
        int x;
        int y;
        int v;
        std::tie(x, y, v) = c;
        std::cout << x << y << v << std::endl;
    }
    matrix[100][100] = -1;
    assert(matrix.Size() == 0);
    // 1. заполнить главную диагональ матрицы (от \[0,0\] до \[9,9\]) значениями от 0 до 9.
    for (auto i = 0; i < 10; i++)
        matrix[i][i] = i;
    // 2. Второстепенную диагональ (от \[0,9\] до \[9,0\]) значениями от 9 до 0.
    for (auto i = 0, j = 9; i < 10; i++, j--)
        matrix[i][j] = j;


 
    // 3. Необходимо вывести фрагмент матрицы от \[1,1\] до \[8,8\]. Между столбцами пробел. Каждая строка матрицы на новой строке консоли.
    for (auto i = 1; i < 9; i++) {
        for (auto j = 1; j < 9; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // 4. Вывести количество занятых ячеек.
    std::cout << "size: " << matrix.Size() << std::endl;
    //5. Вывести все занятые ячейки вместе со своими позициями.
    for (auto c : matrix) {
        int x, y, v;
        std::tie(x, y, v) = c;
        std::cout <<"[" << x <<"] "<<"["<< y<<"] = " << v << std::endl;
    }    
    return 0;
    
}
