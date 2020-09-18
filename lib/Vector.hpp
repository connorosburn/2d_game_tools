#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>

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
};

#endif