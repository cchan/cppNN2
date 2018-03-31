#pragma once
#include <vector>
#include <ostream>
#include <string>

namespace cppNN{

template<typename T>
class vec : public std::vector<T>{
public:
  using std::vector<T>::vector;
  vec<T>() : std::vector<T>::vector(){}
  vec<T>(std::vector<T> v) : std::vector<T>::vector(v){}

  //Vector addition
  vec<T> operator+(const vec<T>& other) const;
  vec<T>& operator+=(const vec<T>& other);

  //Vector subtraction
  vec<T> operator-(const vec<T>& other) const;
  vec<T>& operator-=(const vec<T>& other);

  //Vector negation
  vec<T> operator-() const;

  std::string toString() const;

  T dot(const vec<T>& other) const; // dot product
  //T mul(const vec<T>& other) const; // element-wise

  //T index(const vec<int>& other) const; //Extract from the first vector the indices indicated in the old vector.

  //Vector-scalar add/sub: broadcasts d as a vector of <d, d, d, ... d>
  //vec operator+(double d) const;
  //friend vec operator+(double d, const vec& a) const;
  //vec operator-(const vec& a, double d);
  //vec operator-(double d, const vec& a);

  //Scalar-vector multiplication
  //vec operator*(double d, vec a);
  //vec operator*(vec a, double d);
};

}

#include "vectors.cpp"
