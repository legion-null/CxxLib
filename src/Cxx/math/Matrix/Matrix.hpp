#pragma once

#include "Cxx/base/Object/Object.h"

namespace Cxx {
namespace math {

template<class E>
template_class Matrix: extends Cxx::base::Object {
CXX_TEMPLATE_OBJECT_DEF(Cxx::math::Matrix)

public:

protected:
	E **matrix = nullptr;
	i32 rows = 0;
	i32 cols = 0;

public:
	Matrix<E>() {

	}

	virtual ~Matrix() {

	}

public:
	Matrix<E>(E *matrix, i32 rows, i32 cols) {
		Copy(matrix, (E*) (this->matrix), rows * cols);

		this->rows = rows;
		this->cols = cols;
	}

protected:
	bool isLegal(i32 row, i32 col) const {
		if (row < 0 || row >= rows || col < 0 || col >= cols)
			return false;
		return true;
	}

	E& getValue(i32 row, i32 col) const {
		if (isLegal(row, col) == false)
			throw Cxx::base::Exception();

		return ((E[rows][cols]) matrix)[row][col];
	}

public:
	bool isFloorEqual(Matrix<E> &other) {
		if (rows != other.rows || cols != other.cols)
			return false;

		return true;
	}

public:
	E get(i32 row, i32 col) const {
		return getValue(row, col);
	}

	void set(i32 row, i32 col, E &value) {
		getValue(row, col) = value;
	}

public:
	Matrix<E>& transpose(){

		return self;
	}

public:
	Matrix<E>& addNum(E &num) {
		for (i32 i = 0; i < rows; i++)
			for (i32 j = 0; j < cols; j++)
				set(i, j, get(i, j) + num);

		return self;
	}

	Matrix<E>& multiNum(E &num) {
		for (i32 i = 0; i < rows; i++)
			for (i32 j = 0; j < cols; j++)
				set(i, j, get(i, j) * num);

		return self;
	}

public:
	Matrix<E>& add(Matrix<E> &other) {
		if (isFloorEqual(other) == false)
			throw Cxx::base::Exception();

		for (i32 i = 0; i < rows; i++)
			for (i32 j = 0; j < cols; j++)
				set(i, j, get(i, j) + other.get(i, j));

		return self;
	}

	Matrix<E>& sub(Matrix<E> &other) {
		if (isFloorEqual(other) == false)
			throw Cxx::base::Exception();

		for (i32 i = 0; i < rows; i++)
			for (i32 j = 0; j < cols; j++)
				set(i, j, get(i, j) - other.get(i, j));

		return self;
	}

};

CXX_TEMPLATE_OBJECT_REALIZATION(Cxx::math::Matrix)

}
}
