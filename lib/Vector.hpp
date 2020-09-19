#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>
#include <cmath>

template <class T, int SIZE>

struct Vector : private std::vector<T> {
    using std::vector<T>::size;
    using std::vector<T>::operator[];

    Vector(): std::vector<T>(SIZE) {};
    Vector(const std::vector<T>& init): std::vector<T>(init) {
        if(init.size() != SIZE) {
            throw "Size mismatch between initialization std::vector and Vector<T>";
        }
    }

    bool operator==(const Vector<T, SIZE>& vec) const {
        for(int i = 0; i < SIZE; i++) {
            if(vec[i] != (*this)[i]) {
                return false;
            }
        }
        return true;
    }

    bool isApproximationOf(const Vector<T, SIZE>& vec, const T epsilon) const {
        for(int i = 0; i < SIZE; i++) {
            if(std::abs(vec[i] - (*this)[i]) > epsilon) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Vector<T, SIZE>& vec) const {
        return !(vec == *this);
    }

    Vector<T, SIZE> operator+(const Vector<T, SIZE>& vec) const {
        Vector<T, SIZE> added;
        auto operation = [](T t1, T t2) {
            return t1 + t2;
        };
        std::transform(this->begin(), this->end(), vec.begin(), added.begin(), operation);
        return added;
    }

    void operator+=(const Vector<T, SIZE>& vec) {
        for(int i = 0; i < SIZE; i++) {
            (*this)[i] += vec[i];
        }
    }

    Vector<T, SIZE> operator-(const Vector<T, SIZE>& vec) const {
        Vector<T, SIZE> subtracted;
        auto operation = [](T t1, T t2) {
            return t1 - t2;
        };
        std::transform(this->begin(), this->end(), vec.begin(), subtracted.begin(), operation);
        return subtracted;
    }

    void operator-=(const Vector<T, SIZE>& vec) {
        for(int i = 0; i < SIZE; i++) {
            (*this)[i] -= vec[i];
        }
    }

    Vector<T, SIZE> operator*(const T scalar) const {
        Vector<T, SIZE> scaled;
        auto operation = [scalar](T element) {
            return element * scalar;
        };
        std::transform(this->begin(), this->end(), scaled.begin(), operation);
        return scaled;
    }

    void operator*=(const T scalar) {
        for(T& element : *this) {
            element *= scalar;
        }
    }

    Vector<T, SIZE> operator/(const T scalar) const {
        Vector<T, SIZE> scaled;
        auto operation = [scalar](T element) {
            return element / scalar;
        };
        std::transform(this->begin(), this->end(), scaled.begin(), operation);
        return scaled;
    }

    void operator/=(const T scalar) {
        for(T& element : *this) {
            element /= scalar;
        }
    }

    T operator*(const Vector<T, SIZE>& vec) {
        T sum { 0 };
        for(int i = 0; i < SIZE; i++) {
            sum += (*this)[i] * vec[i];
        }
        return sum;
    }

    Vector<T, SIZE> unit() {
        return (*this) / std::sqrt((*this) * (*this));
    }
};

#endif