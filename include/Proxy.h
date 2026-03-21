#pragma once

#include "Matrix.h"
#include <memory>

template<class T, T N>
class Matrix;


template<class T, T N>
class Proxy {
public:
    Proxy(Matrix<T, N>* matrixPtr_, long x_) :
        matrixPtr(matrixPtr_),  x(x_)
    {
    };

    ~Proxy() {
    };

    Proxy& operator[](int y) {
        this->y = y;
        // Запрашиваем текущее значение из матрицы по координатам (x, y)
        // и сохраняем его в локальную переменную element.     
        element = matrixPtr->getValueAt(x, y);
        return *this;
    };

    void operator=(T newValue) {
        matrixPtr->setValueAt(x, y, newValue);
    }
    operator T() const { //ДЛЯ assert(a == -1);
        return element;
    }
private:
    //int size;
    long y;
    long x;  
    T element;
    Matrix<T, N>* matrixPtr;
};
