#pragma once
#include <iostream>
#include <cstring>
#include <utility>
#include <atomic>

class MyString {
private:
    static const size_t SSO_THRESHOLD = 15;

    union {
        char ssoBuffer[SSO_THRESHOLD + 1]; 
        struct {
            char* str;
            size_t length;
            size_t capacity;
            std::atomic<size_t>* refCount; 
        };
    };

    bool isSSO() const;
    void setSSOMode(bool sso);
    void copyOnWrite();

public:

    MyString(const char* s = "");
    MyString(const MyString& other);
    MyString(MyString&& other) noexcept;
    ~MyString();

    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other) noexcept;

    size_t getLength() const;
    void append(char c);

    void print() const {
        std::cout << (isSSO() ? ssoBuffer : str) << std::endl;
    }
};

#include "string.inl"


