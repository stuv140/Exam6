#pragma once
#include<tuple>
template<class T>
class Element {
public:
    Element(long x, long y, T value) : x_(x), y_(y), value_(value) {}

    long X() const { return x_; }
    long Y() const { return y_; }
    T Value() const { return value_; }
    void SetValue(T value) { value_ = value; }
    //   возвращает std::tuple с координатами и значением
    auto AsTuple() const {
        return std::make_tuple(x_, y_, value_);
    }
private:
    long x_;
    long y_;
    T value_;
};