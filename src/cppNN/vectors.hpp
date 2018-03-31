#pragma once
#include <vector>
#include <ostream>
#include <string>
#include <algorithm>
#include <functional>

namespace cppNN{

template<typename T>
class vec : public std::vector<T>{
  template<typename O, typename R> inline vec<R> binOp(const vec<O>& other, std::function<R(T,O)> func) const;
  template<typename O> inline vec<T>& binOpAssign(const vec<O>& other, std::function<T(T,O)> func);
  template<typename R> inline vec<R> unaryOp(std::function<R(T)> func) const;
  inline vec<T>& unaryOpAssign(std::function<T(T)> func);
public:
  using std::vector<T>::vector;
  vec<T>() : std::vector<T>::vector(){}
  vec<T>(std::vector<T> v) : std::vector<T>::vector(v){}

  std::string toString() const;

  // Vector-vector arithmetic
  template<typename O> vec<T> operator+(const vec<O>& other) const{ return binOp(other, std::function<T(T,O)>(std::plus<T>())); }
  //template<typename O> vec<T>& operator+=(const vec<O>& other){ return binOpAssign(other, [](T x, O y){return x + y;}); }
  template<typename O> vec<T> operator-(const vec<O>& other) const{ return binOp(other, std::function<T(T,O)>(std::minus<T>())); }
  //template<typename O> vec<T>& operator-=(const vec<O>& other){ return binOpAssign(other, [](T x, O y){return x - y;}); }

  // Scalar-vector arithmetic
  //template<typename O> vec<T> operator+(O d) const{ return unaryOp(std::bind1st([](T x, O y){return x + y;}, d)); }
  //template<typename O> vec<T>& operator+=(O d){ return unaryOpAssign(std::bind1st([](T x, O y){return x + y;}, d)); }
  //template<typename O> vec<T> operator-(O d) const{ return unaryOp(std::bind1st([](T x, O y){return x - y;}, d)); }
  //template<typename O> vec<T>& operator-=(O d){ return unaryOpAssign(std::bind1st([](T x, O y){return x - y;}, d)); }
  //template<typename O> vec<T> operator*(O d) const{ return unaryOp(std::bind1st([](T x, O y){return x * y;}, d)); }
  //template<typename O> vec<T>& operator*=(O d){ return unaryOpAssign(std::bind1st([](T x, O y){return x * y;}, d)); }
  //template<typename O> vec<T> operator/(O d) const{ return unaryOp(std::bind1st([](T x, O y){return x / y;}, d)); }
  //template<typename O> vec<T>& operator/=(O d){ return unaryOpAssign(std::bind1st([](T x, O y){return x / y;}, d)); }

  // Vector negation
  vec<T> operator-() const{ return unaryOp(std::function<T(T)>(std::negate<T>())); }

  // Dot and element-wise products
  T dot(const vec<T>& other) const;
  //template<typename O> vec<T> mul(const vec<O>& other) const{ return binOp(other, std::multiplies<T>()); }

  // Comparison
  bool operator==(const vec<T>& other) const{ return this->size() == other.size() && std::equal(this->begin(), this->end(), other.begin()); }

  // Indexing
  //vec<T> at(vec<size_t> indices){ return indices.unaryOp(std::function<T(size_t)>([this](size_t x){return std::vector<T>::at(x);})); }
  void set(size_t index, T value){ this->at(index) = value; }
};

}

#include "vectors.cpp"
