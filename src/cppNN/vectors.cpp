#include <sstream>

namespace cppNN{

template<typename T>
std::string vec<T>::toString() const{
  std::stringstream ss;
  if (data.size() == 0)
    ss << "{}";
  else{
    ss << '{' << data[0];
    for (size_t i = 1; i < data.size(); i++)
      ss << ',' << data[i];
    ss << '}';
  }
  return ss.str();
}

template<typename T>
template<typename O, typename R>
inline vec<R> vec<T>::binOp(const vec<O>& other, std::function<R(T,O)> func) const{
  assert(data.size() == other.data.size(), ERR_SIZE_MISMATCH);
  vec<R> result;
  result.data.reserve(data.size());
  std::transform(data.begin(), data.end(), other.data.begin(),
                 std::back_inserter(result.data), func);
  return result;
}

template<typename T>
template<typename O>
inline vec<T>& vec<T>::binOpAssign(const vec<O>& other, std::function<T(T,O)> func){
  assert(data.size() == other.data.size(), ERR_SIZE_MISMATCH);
  std::transform(data.begin(), data.end(), other.data.begin(),
                 data.begin(), func);
  return *this;
}

template<typename T>
template<typename R>
inline vec<R> vec<T>::unaryOp(std::function<R(T)> func) const{
  vec<R> result;
  result.data.reserve(data.size());
  std::transform(data.begin(), data.end(),
                 std::back_inserter(result.data), func);
  return result;
}

template<typename T>
inline vec<T>& vec<T>::unaryOpAssign(std::function<T(T)> func){
  std::transform(data.begin(), data.end(),
                 data.begin(), func);
  return *this;
}

}
