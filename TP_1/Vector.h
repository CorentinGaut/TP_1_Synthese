#pragma once
#include <iostream>

template<typename T>
struct Vec3 {
	T x, y, z;
};


//Operateur egalitaire
template<typename T>
bool operator==(const Vec3<T>& a, const Vec3<T>& b) {
	return a.x == b.x && a.y == b.y && a.z == b.z;
};

//Operateur multiplicateur
template<typename T>
Vec3<T> operator*(const Vec3<T>& a, const Vec3<T>& b) {
	return Vec3<T>{ a.x * b.x, a.y * b.y, a.z * b.z };
};

//Operateur diviseur
template<typename T>
Vec3<T> operator/(const Vec3<T>& a, const Vec3<T>& b) {
	return Vec3<T>{ a.x / b.x, a.y / b.y, a.z / b.z };
};

//Operateur de soustraction
template<typename T>
Vec3<T> operator-(const Vec3<T>& a, const Vec3<T>& b) {
	return Vec3<T>{ a.x - b.x, a.y - b.y, a.z - b.z };
};

//Operateur d'addition
template<typename T>
Vec3<T> operator+(const Vec3<T>& a, const Vec3<T>& b) {
	return Vec3<T>{ a.x + b.x, a.y + b.y, a.z + b.z };
};


//Calcul de la nomre d'un vecteur
template<typename T>
float norm(const Vec3<T>& v) {
	return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
};

template<typename T>
Vec3<T> normalize(const Vec3<T>& v) {
	float norme = norm(v);
	return Vec3<T>{ v.x / norme, v.y / norme, v.z / norme };
}


//Calcul du produit scalaire
template<typename T>
float dot(const Vec3<T>& a, const Vec3<T>&b) {
	return a.x* b.x + a.y * b.y + a.z * b.z;
}

