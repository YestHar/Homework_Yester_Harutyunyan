#include <iostream>

class Vector3 {
private:
    double x, y, z;
public:
    Vector3(double x, double y, double z) : x(x), y(y), z(z) {}
    Vector3 operator+(const Vector3& V2) const;
    Vector3 operator+(const double num) const; 
    Vector3 operator*(const Vector3& V2) const;
    Vector3 operator-(const Vector3& V2) const;
    Vector3 operator/(const Vector3& V2) const;
    Vector3 operator++();
    Vector3 operator++(int);
    Vector3 operator--();
    Vector3 operator--(int);
    bool operator==(const Vector3& V2) const;
    bool operator!=(const Vector3& V2) const;
    template <typename Out>
    friend Out& operator<<(Out& os, Vector3& V);
};

Vector3 Vector3::operator+(const Vector3& V2) const {
    return Vector3(x + V2.x, y + V2.y, z + V2.z);
}

Vector3 Vector3::operator+(const double num) const {
    return Vector3(x + num, y + num, z + num);
}

Vector3 Vector3::operator*(const Vector3& V2) const {
    return Vector3(x * V2.x, y * V2.y, z * V2.z);
}

Vector3 Vector3::operator-(const Vector3& V2) const {
    return Vector3(x - V2.x, y - V2.y, z - V2.z);
}

Vector3 Vector3::operator/(const Vector3& V2) const {
    return Vector3(x / V2.x, y / V2.y, z / V2.z);
}

Vector3 Vector3::operator++(){
    return Vector3(++x, ++y, ++z);
}

Vector3 Vector3::operator++(int){
    return Vector3(++x, ++y, ++z);
}

Vector3 Vector3::operator--(){
    return Vector3(--x, --y, --z);
}

Vector3 Vector3::operator--(int){
    return Vector3(--x, --y, --z);
}

bool Vector3::operator!=(const Vector3& V2) const {
    if (x != V2.x || y != V2.y || z != V2.z) {
        return true;
    }
    return false;
}

bool Vector3::operator==(const Vector3& V2) const {
    if (x == V2.x && y == V2.y && z == V2.z) {
        return true;
    }
    return false;
}

template <typename Out>
Out& operator<<(Out& os, Vector3& V) {
    os << '(' << V.x << ',' << V.y << ',' << V.z << ')';
    return os;
}

int main() {
    Vector3 V1(2,9,10);
    Vector3 V2(1,3,5);
    Vector3 V3 = V1 + V2;
    std::cout << "V1 + V2:" << V3 << std::endl;
    V3 = V1 + 2;
    std::cout << "V1 + num:" << V3 << std::endl;
    V3 = V1 * V2;
    std::cout << "V1 * V2:" << V3 << std::endl;
    V3 = V1 - V2;
    std::cout << "V1 - V2:" << V3 << std::endl;
    V3 = V1 / V2;
    std::cout << "V1 / V2:" << V3 << std::endl;
    V3 = V1++;
    std::cout << "V++:" << V3 << std::endl;
    V3 = ++V2;
    std::cout << "++V:" << V3 << std::endl;
    V3 = V1--;
    std::cout << "V--:" << V3 << std::endl;
    V3 = --V2;
    std::cout << "--V:" << V3 << std::endl;
    if (V2 == V3) {
        std::cout << "V2 == V3:" << "True" << std::endl;
    }
    if (V1 != V2) {
        std::cout << "V1 != V2:" << "True" << std::endl;
    }
    return 0;
}