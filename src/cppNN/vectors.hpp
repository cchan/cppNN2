#pragma once
#include <vector>
#include <ostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include "common.hpp"

namespace cppNN{

template<typename T>
class vec{
public:
  std::vector<T> data;

  typedef int size_type;

  template<typename O, typename R> inline vec<R> binOp(const vec<O>& other, std::function<R(T,O)> func) const;
  template<typename O> inline vec<T>& binOpAssign(const vec<O>& other, std::function<T(T,O)> func);
  template<typename R> inline vec<R> unaryOp(std::function<R(T)> func) const;
  inline vec<T>& unaryOpAssign(std::function<T(T)> func);

  vec<T>() : data(){}
  vec<T>(std::vector<T> v) : data(v){}
  vec<T>(std::initializer_list<T> v) : data(v){}

  std::string toString() const;

  #define RESULT(T,op,O) decltype(std::declval<T>() op std::declval<O>())
  #define OP(T,op,O) (std::function<RESULT(T,op,O)(T,O)>([](T x, O y){return x op y;}))
  // #define BINOP(op) template<typename O> auto operator##op(const vec<O>& other) const{ return binOp(other, OP(T,op,O)); }

  // Vector-vector arithmetic
  template<typename O> auto operator+(const vec<O>& other) const{ return binOp(other, OP(T,+,O)); }
  template<typename O> vec<T>& operator+=(const vec<O>& other){ return binOpAssign(other, OP(T,+,O)); }
  template<typename O> auto operator-(const vec<O>& other) const{ return binOp(other, OP(T,-,O)); }
  template<typename O> vec<T>& operator-=(const vec<O>& other){ return binOpAssign(other, OP(T,-,O)); }

  // Scalar-vector arithmetic
  //template<typename O> friend auto operator+(vec<T> a, O b){ return a.unaryOp(std::bind2nd(OP(T,+,O), b)); }
  //template<typename O> friend vec<T>& operator+=(vec<T> a, O b){ return a.unaryOpAssign(std::bind2nd(OP(T,+,O), b)); }
  //template<typename O> auto operator-(O d) const{ return unaryOp(std::bind2nd(OP(T,-,O), d)); }
  //template<typename O> vec<T>& operator-=(O d){ return unaryOpAssign(std::bind2nd(OP(T,-,O), d)); }
  //template<typename O> auto operator*(O d) const{ return unaryOp(std::bind2nd(OP(T,*,O), d)); }
  //template<typename O> vec<T>& operator*=(O d){ return unaryOpAssign(std::bind2nd(OP(T,*,O), d)); }
  //template<typename O> auto operator/(O d) const{ return unaryOp(std::bind2nd(OP(T,/,O), d)); }
  //template<typename O> vec<T>& operator/=(O d){ return unaryOpAssign(std::bind2nd(OP(T,/,O), d)); }

  // Vector negation
  vec<T> operator-() const{ return unaryOp(std::function<T(T)>(std::negate<T>())); }

  // Dot and element-wise products
  template<typename O> T dot(const vec<O>& other) const{
    assert(data.size() == other.data.size(), ERR_SIZE_MISMATCH);
    return std::inner_product(data.begin(), data.end(), other.data.begin(), T());
  }
  template<typename O> auto mul(const vec<O>& other) const{ return binOp(other, OP(T,*,O)); }

  // Comparison
  template<typename O> bool operator==(const vec<O>& other) const{
    return data.size() == other.data.size() &&
           std::equal(data.begin(), data.end(), other.data.begin());
  }

  // Indexing
  T at(size_type i){ return data.at(i); }
  vec<T> idx(const std::vector<size_type>& indices) const{
    return idx(vec<size_type>(indices));
  }
  vec<T> idx(const vec<size_type>& indices) const{
    return indices.unaryOp(
      std::function<T(size_type)>(
        [this](size_type x){
          return data.at(x);
        }
      )
    );
  }
  void set(size_type index, T value){ data.at(index) = value; }
};

}

#include "vectors.cpp"
