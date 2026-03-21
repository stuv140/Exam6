#pragma once
#include<vector>
#include<memory>
#include<algorithm>
#include<tuple>
#include"Element.h"
#include"Proxy.h"
template<class T, T N>
class Matrix {
	friend class Proxy<T, N>; // Делаем Proxy другом, чтобы он мог вызывать приватные методы
	template<typename ValType>
	class MatrixIterator {
	public:
		using iterator_category = std::forward_iterator_tag;
		using value_type = std::tuple<long, long, ValType>;
		using difference_type = std::ptrdiff_t;
		using pointer = value_type*;
		using reference = value_type;
		explicit MatrixIterator(typename std::vector<std::unique_ptr<Element<ValType>>>::iterator it) : internal_it(it) {}

		// Оператор разыменования *it
		reference operator*() const {
			auto& elem_ptr = *internal_it;
			// Возвращаем кортеж (x, y, value)
			return std::make_tuple(elem_ptr->X(), elem_ptr->Y(), elem_ptr->Value());
		}

		pointer operator->() { return &(operator*()); }

		MatrixIterator& operator++() { ++internal_it; return *this; }
		MatrixIterator operator++(int) { auto tmp = *this; ++(*this); return tmp; }

		friend bool operator==(const MatrixIterator& a, const MatrixIterator& b) { return a.internal_it == b.internal_it; }
		friend bool operator!=(const MatrixIterator& a, const MatrixIterator& b) { return a.internal_it != b.internal_it; }
	private:
		typename std::vector<std::unique_ptr<Element<ValType>>>::iterator internal_it;
	};

public:
	Matrix() : default_element(N) {
		size=0;
	};
	~Matrix() {};
	Proxy<T, N> operator[](long x) {
		Proxy<T, N> proxy(this, x);
		return proxy;
	};
	size_t Size()const {
		return matrix.size();
	}
	T getDefaultElement() {
		return default_element;
	};
	void removeElement(std::pair<long, long> coordinates) {
		//matrix.erase(matrix.find(coordinates));
	};
	
	void insertElement(std::pair<long, long> coordinates, T value) {
		//matr.emplace(coordinates, value);
		size++;
	};
	void emplace(std::pair<long, long> coordinates, T value) {

	}
	int find(std::pair<long, long> coordinates) {
		return 0;
	}
	// Методы для поддержки range - based for 
		MatrixIterator<T> begin() {
		return MatrixIterator<T>(matrix.begin());
	}
	MatrixIterator<T> end() {
		return MatrixIterator<T>(matrix.end());
	}

	// Методы для поддержки range-based for c const Matrix 
	MatrixIterator<const T> begin() const {

		return MatrixIterator<T>(const_cast<std::vector<std::unique_ptr<Element<T>>> &>(matrix).begin());
		
	}
	MatrixIterator<const T> end() const {
		return MatrixIterator<T>(const_cast<std::vector<std::unique_ptr<Element<T>>> &>(matrix).end());
	}
private:
	// Метод для получения значения (для чтения и приведения типа)
	T getValueAt(long x, long y) const {
		auto it = std::find_if(matrix.begin(), matrix.end(),
			[x, y](const std::unique_ptr<Element<T>>& elem) {
				return elem->X() == x && elem->Y() == y;
			});
		if (it != matrix.end()) {
			return (*it)->Value();
		}
		return default_element;
	}
	// Метод для поиска ячейки (для записи или удаления)
	void setValueAt(long x, long y, T newValue) {
		auto it = std::find_if(matrix.begin(), matrix.end(),
			[x, y](const std::unique_ptr<Element<T>>& elem) {
				return elem->X() == x && elem->Y() == y;
			});

		if (it != matrix.end()) {
			// Элемент найден. Если новое значение равно дефолтному - удаляем.
			if (newValue == default_element) {
				matrix.erase(it); // Удаляем из вектора 
				size--;
			}
			else {
				(*it)->SetValue(newValue); // Просто меняем значение
			}
		}
		else {
			// Элемента нет. Если значение не дефолтное - создаем новый.
			if (newValue != default_element) {
				matrix.push_back(std::make_unique<Element<T>>(x, y, newValue));
				size++;
			}
		}
	}
	size_t size;
	const T default_element;

	std::vector<std::unique_ptr<Element<T>>> matrix;
};

