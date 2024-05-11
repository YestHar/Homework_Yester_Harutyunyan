#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>

template <typename T>
class Vector {
private:
    T* data;
    size_t _size;
    size_t _capacity;

public:
    Vector();
    Vector(size_t size);
    Vector(const Vector& other); //Copy constructor
    ~Vector();

    //Iterators

    class VectorIterator {
    private:
        T* m_iter;
    public:
        VectorIterator(T* p) {
            m_iter = p;
        }

        VectorIterator& operator++() {
            ++m_iter;
            return *this;
        };

        VectorIterator& operator--() {
            --m_iter;
            return *this;
        };

        T& operator*() {
            return *m_iter;
        }

        bool operator==(const VectorIterator& other) const {
            return m_iter == other.m_iter;
        };

        bool operator!=(const VectorIterator& other) const {
            return !(*this == other);
        };
    };

    const VectorIterator begin()const;
    const VectorIterator end() const;    

    //Capacity

    const size_t size() const;
    const size_t capacity() const;
    void resize(size_t size, T value = 0);
    void reserve(size_t capacity);
    bool empty();

    //Element access

    T& operator[] (size_t index);
    const T& operator[](size_t index) const;
    Vector& operator= (const Vector& other); 
    T& at(size_t index);
    const T& at(size_t index) const;
    T& front();
    T& back();
    T* get_data();

    //Modifiers

    void push_back(T value);
    void pop_back();
    void insert(size_t position, const T& value);
    //Swap the two elements of vector
    void swap(size_t first_position, size_t second_position);
    //Swap two vectors
    void swap(Vector& newVector);
    void erase(size_t position, size_t end_position = 0);
    void clear();

};

#include "vector.inl"
#endif //VECTOR_HPP