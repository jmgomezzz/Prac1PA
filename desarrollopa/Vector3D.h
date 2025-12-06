#pragma once
#include <GL/glut.h>
class Vector3D
{
private:
	float X;
	float Y;
	float Z;
public:
	Vector3D() :X(0.0), Y(0.0), Z(0.0) {

	}
	Vector3D(float CX, float CY, float CZ){
		this->X = CX;
		this->Y = CY;
		this->Z = CZ;
	}
	inline float GetX() { return this->X; }
	inline float GetY() { return this->Y; }
	inline float GetZ() { return this->Z; }

	inline void SetX(const float& XToSet) { this->X = XToSet; }
	inline void SetY(const float& YToSet) { this->Y = YToSet; }
	inline void SetZ(const float& ZToSet) { this->Z = ZToSet; }

	Vector3D Add(const Vector3D& b);
	Vector3D Substract(const Vector3D& b);
	Vector3D Product(const float& b);
	float DotProduct(const Vector3D& v);
	float Magnitude();

	Vector3D operator+(const Vector3D& vector);
	Vector3D operator-(const Vector3D& vector);
	Vector3D operator*(const float& value);
	Vector3D operator/(const float& value);
	float operator* (const Vector3D& vector);
	
};

