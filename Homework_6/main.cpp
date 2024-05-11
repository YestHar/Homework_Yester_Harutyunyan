#include "vector.hpp"

int main() {
    Vector<int> v;
    for(int i = 0; i < 5; ++i) {
        v.push_back(i);
    }

    Vector<int> v1;
    for(int i = 10; i < 15; ++i) {
        v1.push_back(i);
    }


    // std::cout<<"size = "<<v.size()<<std::endl;
    // std::cout<<"capacity = "<<v.capacity()<<std::endl;
    // v.resize(10);
    // v.reserve(3);
    // v1 = v;

    // size_t first = v.front();
    // v.front() = 4;
    // size_t last = v.back();
    // v.back() = 111;
    // std::cout<<"at:"<<v.at()<<std::endl;
    // v.push_back(1);
    // v.pop_back();
    // v.insert(2,8);
    // v.swap(1,14);
    // v.swap(v1);
    // v1.erase(2,3);
    // v.clear();
    
    for(size_t i = 0; i < v.size(); i++){
        std::cout<<v[i]<<std::endl;
    }

    for(auto i = v1.begin(); i != v1.end(); ++i){
        std::cout<< *i <<std::endl;
    }

    return 0;
}