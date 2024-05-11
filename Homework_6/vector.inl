#ifndef VECTOR_INL
#define VECTOR_INL

#include "vector.hpp"

template <typename T>
Vector<T>::Vector() {
    data = nullptr;
    this->_size = 0;
    this->_capacity = 0;
}

template <typename T>
Vector<T>::Vector(size_t size) {
    this->_size = size;
    this->_capacity = 2 * size;
    data = (T*)malloc(_capacity * sizeof(T));
}

template <typename T>
Vector<T>::Vector(const Vector& other) : data((T*)malloc(other._capacity * sizeof(T))), _size(other._size), _capacity(other._capacity){
    for(size_t i = 0; i < _size; ++i){
        data[i] = other.data[i];
    }
}

template <typename T>
Vector<T>::~Vector() {
    free(data);
}

//Iterators

template <typename T>
const typename Vector<T>::VectorIterator Vector<T>::begin() const {
    return VectorIterator(data);
}

template <typename T>
const typename Vector<T>::VectorIterator Vector<T>::end() const {
    return VectorIterator(data + _size);
}

//Capacity

template <typename T>
const size_t Vector<T>::size() const {
    return _size;
}

template <typename T>
const size_t Vector<T>::capacity() const {
    return _capacity;
}

template <typename T>
bool Vector<T>::empty() {
    if (_size == 0) {
        return true;
    }
    return false;
}

template <typename T>
void Vector<T>::reserve(size_t capacity) {
    if (capacity > _capacity) {
        _capacity = capacity;

        T* current = (T*)realloc(data, sizeof(T) * _capacity);

        if (current == NULL) {
            current = (T*) malloc(sizeof(T) * _capacity);
            if(current == NULL) {
                throw("Bad allocation");
            }

            for (size_t i = 0; i < _size; ++i) {
                current[i] = data[i];
            }

            free(data);
        }

        data = current;
        current = NULL;
    }
}

template <typename T>
void Vector<T>::resize(size_t size, T value) {
    if (size < _size) {
        _size = size;
    } else {
        for (size_t i = 0; i < _size - size; i++) {
            push_back(value);
        }
    }
}

//Element access

template <typename T>
T& Vector<T>::operator[] (size_t index) {
    return data[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    return data[index];
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this != &other) {
        free(data);
        _capacity = other._capacity;
        _size = other._size;
        data = (T*)malloc(_capacity * sizeof(T));
        if(data == NULL) {
            throw("Bad allocation");
        }
        for (size_t i = 0; i < _size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
T& Vector<T>::at(size_t index) {
    if (index <= _size) {
        return data[index];
    }
    throw("Index is out of range");
}

template <typename T>
const T& Vector<T>::at(size_t index) const {
    if (index <= _size) {
        return data[index];
    }
    throw("Index is out of range");
}

template <typename T>
T& Vector<T>::front() {
    if (empty()) {
        throw std::out_of_range("Vector is empty");
    }
    return data[0];
}

template <typename T>
T& Vector<T>::back() {
    if (empty()) {
        throw std::out_of_range("Vector is empty");
    }
    return data[_size - 1];
}

template <typename T>
T* Vector<T>::get_data() {
    return data;
}

//Modifiers

template <typename T>
void Vector<T>::push_back(T value) {
    if (_capacity <= _size) {
        size_t newCapacity = _capacity == 0 ? 1 : _capacity * 2;

        T* current = (T*)realloc(data, sizeof(T) * newCapacity);

        if (current == NULL) {
            current = (T*) malloc(sizeof(T) * newCapacity);
            if(current == NULL) {
                throw("Bad allocation");
            }

            for (size_t i = 0; i < _size; ++i) {
                current[i] = data[i];
            }

            free(data);
        }

        _capacity = newCapacity;
        data = current;
        current = NULL;
    }
    data[_size] = value;
    ++_size;
}

template <typename T>
void Vector<T>::pop_back() {
    if (_size != 0) {
        --_size;
    }
}

template <typename T>
void Vector<T>::insert(size_t position, const T& value) {
    if(position > _size) {
        throw std::out_of_range("Position is out of range");
    }
    if(_size >= _capacity) {
        _capacity = (_capacity == 0) ? 1 : _capacity * 2;
        T* current = (T*)realloc(data, sizeof(T) * _capacity);

        if (current == NULL) {
            current = (T*) malloc(sizeof(T) * _capacity);
            if(current == NULL) {
                std::cerr << "Bad allocation" << std::endl;
                return;
            }

            for (size_t i = 0; i < position; ++i) {
                current[i] = data[i];
            }
            current[position] = value;
            for (size_t i = position + 1; i < _size + 1; ++i) {
                current[i] = data[i - 1];
            }

            free(data);
            data = current;
            current = NULL;
            ++_size;
            
            return;
        }

        data = current;
        current = NULL;
    }
    
    for (size_t i = _size - 1; i >= position; --i) {
        data[i + 1] = data[i];
    }
    data[position] = value;
    ++_size;
}

template <typename T>
void Vector<T>::swap(size_t first_position, size_t second_position) {
    if (first_position <= _size && second_position <= _size) {
        T current = data[first_position];
        data[first_position] = data[second_position];
        data[second_position] = current;
    } else {
        throw std::out_of_range("Index is out of range");
    }
};

template <typename T>
void Vector<T>::swap(Vector& newVector) { 
    if (this != &newVector) {
        auto swapVector = [](Vector& v1, Vector& v2) {
            v1._capacity = v2._capacity;
            v1._size = v2._size;
            v1.data = (T*)malloc(v1._capacity * sizeof(T));
            for (size_t i = 0; i < v1._size; ++i) {
                v1.data[i] = v2.data[i];
            }  
        };

        Vector currentVector;
        swapVector(currentVector, newVector);
        swapVector(newVector, *this);
        swapVector(*this, currentVector);
    }
};

template <typename T>
void Vector<T>::erase(size_t position, size_t end_position) {
    if (position == _size - 1) {
        pop_back();
    } else if (position >= _size) {
        throw std::out_of_range("Index is out of range");
    } else {
        if (end_position == 0 || position == end_position) {
            for (size_t i = position; i < _size; i++) {
                data[i] = data[i + 1];
            }
            _size = _size - 1;
        } else {
            if (position < end_position) {
                size_t i = position; 
                for (size_t j = end_position - 1; j < _size; j++) {
                    data[i] = data[j + 1];
                    ++i;
                }
                _size = _size - (end_position - position);
            } else {
                throw("End Position have to be bigger than first Position");
            }
            
        }
        
    }
    
}

template <typename T>
void Vector<T>::clear() {
    if (_size != 0) {
        _size = 0;
    }
}

#endif // VECTOR_INL