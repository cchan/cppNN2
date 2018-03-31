#include <numeric>
#include <sstream>
#include "common.hpp"

namespace cppNN{

template<typename T>
std::string vec<T>::toString() const{
  std::stringstream ss;
  if (this->size() == 0)
    ss << "{}";
  else{
    ss << '{' << this->operator[](0);
    for (size_t i = 1; i < this->size(); i++)
      ss << ',' << this->operator[](i);
    ss << '}';
  }
  return ss.str();
}

template<typename T>
template<typename O, typename R>
inline vec<R> vec<T>::binOp(const vec<O>& other, std::function<R(T,O)> func) const{
  assert(this->size() == other.size(), ERR_SIZE_MISMATCH);
  vec<R> result;
  result.reserve(this->size());
  std::transform(this->begin(), this->end(), other.begin(),
                 std::back_inserter(result), func);
  return result;
}

template<typename T>
template<typename O>
inline vec<T>& vec<T>::binOpAssign(const vec<O>& other, std::function<T(T,O)> func){
  assert(this->size() == other.size(), ERR_SIZE_MISMATCH);
  std::transform(this->begin(), this->end(), other.begin(),
                 this->begin(), func);
  return *this;
}

template<typename T>
template<typename R>
inline vec<R> vec<T>::unaryOp(std::function<R(T)> func) const{
  vec<R> result;
  result.reserve(this->size());
  std::transform(this->begin(), this->end(),
                 std::back_inserter(result), func);
  return result;
}

template<typename T>
inline vec<T>& vec<T>::unaryOpAssign(std::function<T(T)> func){
  std::transform(this->begin(), this->end(),
                 this->begin(), func);
  return *this;
}


template<typename T>
T vec<T>::dot(const vec<T>& other) const{
  assert(this->size() == other.size(), ERR_SIZE_MISMATCH);
  return std::inner_product(this->begin(), this->end(), other.begin(), T());
}

}
