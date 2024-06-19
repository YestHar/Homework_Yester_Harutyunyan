#include "string.hpp"

int main() {
    MyString s1("Hello");
    s1.print(); 

    s1.append('!');
    s1.print(); 

    MyString s2 = s1;
    s2.print(); 

    MyString s3;
    s3 = s1;
    s3.print(); 

    MyString s4 = std::move(s1);
    s4.print();
    s1.print(); 

    s3.append('!'); 
    s3.print(); 
    s2.print();

    return 0;
}
