#pragma once
#include <vector>
#include <ostream>
#include <string>

//Generic output
template<typename T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& v);
template<typename T> std::string vectorToString(const std::vector<T>& v);

//Vector addition
std::vector<double> operator+(const std::vector<double>& a, const std::vector<double>& b);
std::vector<double> operator+=(std::vector<double>& a, const std::vector<double>& b);

//Vector subtraction
std::vector<double> operator-(const std::vector<double>& a, const std::vector<double>& b);
std::vector<double> operator-=(std::vector<double>& a, const std::vector<double>& b);

//Vector negation
std::vector<double> operator-(const std::vector<double>& a);

//Vector-scalar add/sub: treats d as a vector of <d, d, d, ... d>
std::vector<double> operator+(const std::vector<double>& a, double d);
std::vector<double> operator+(double d, const std::vector<double>& a);
std::vector<double> operator-(const std::vector<double>& a, double d);
std::vector<double> operator-(double d, const std::vector<double>& a);

//Scalar-vector multiplication
std::vector<double> operator*(double d, std::vector<double> a);
std::vector<double> operator*(std::vector<double> a, double d);

//Vector-vector multiplication: Dot Product ( = sum(a_i * b_i) )
double dotProduct(const std::vector<double>& a, const std::vector<double>& b);

//Vector-vector multiplication: Hadamard Product (c_i = a_i * b_i)
std::vector<double> hadamardProduct(const std::vector<double>& a, const std::vector<double>& b);

//Extract from the first vector the indices indicated in the old vector.
template<typename T> std::vector<T> extractIndices(std::vector<T> oldvec, std::vector<size_t> indices);
