#include "Vector3D.h"
#include <cmath>

Vector3D Vector3D::Add(const Vector3D& b) {
    return Vector3D(this->X + b.X, this->Y + b.Y, this->Z + b.Z);
}

Vector3D Vector3D::Substract(const Vector3D& b) {
    return Vector3D(this->X - b.X, this->Y - b.Y, this->Z - b.Z);
}

Vector3D Vector3D::Product(const float& b) {
    return Vector3D(this->X * b, this->Y * b, this->Z * b);
}

float Vector3D::DotProduct(const Vector3D& v) {
    return (this->X * v.X + this->Y * v.Y + this->Z * v.Z);
}

float Vector3D::Magnitude() {
    return std::sqrt(this->X * this->X + this->Y * this->Y + this->Z * this->Z);
}

Vector3D Vector3D::operator+(const Vector3D& vector) {
    return Vector3D(this->X + vector.X, this->Y + vector.Y, this->Z + vector.Z);
}

Vector3D Vector3D::operator-(const Vector3D& vector) {
    return Vector3D(this->X - vector.X, this->Y - vector.Y, this->Z - vector.Z);
}

Vector3D Vector3D::operator*(const float& value) {
    return Vector3D(this->X * value, this->Y * value, this->Z * value);
}

Vector3D Vector3D::operator/(const float& value) {
    return Vector3D(this->X / value, this->Y / value, this->Z / value);
}

float Vector3D::operator*(const Vector3D& vector) {
    return (this->X * vector.X + this->Y * vector.Y + this->Z * vector.Z);
}