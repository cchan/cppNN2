#include <numeric>
#include <cassert>
#include <sstream>


template<typename T>
std::string vec<T>::toString() const{
  std::stringstream os;
	if (this->size() == 0)
		os << "{}";
	else{
		os << '{' << this->operator[](0);
		for (size_t i = 1; i < this->size(); i++)
			os << ',' << this->operator[](i);
		os << '}';
	}
	return os.str();
}

template<typename T>
vec<T> vec<T>::operator+(const vec<T>& other) const{
	assert(this->size() == other.size());
	vec<T>c;
	for (size_t i = 0; i < this->size(); i++)c.push_back(this->operator[](i) + other[i]);
	return c;
}

template<typename T>
vec<T>& vec<T>::operator+=(const vec<T>& other){
	assert(this->size() == other.size());
	for (size_t i = 0; i < this->size(); i++)this->operator[](i) += other[i];
	return *this;
}

template<typename T>
vec<T> vec<T>::operator-(const vec<T>& other) const{
	assert(this->size() == other.size());
	vec<T>c;
	for (size_t i = 0; i < this->size(); i++)c.push_back(this->operator[](i) - other[i]);
	return c;
}
template<typename T>
vec<T>& vec<T>::operator-=(const vec<T>& other){
	assert(this->size() == other.size());
	for (size_t i = 0; i < this->size(); i++)this->operator[](i) -= other[i];
	return *this;
}

template<typename T>
vec<T> vec<T>::operator-() const{
	vec<T>c;
	for (size_t i = 0; i < this->size(); i++)c.push_back(-this->operator[](i));
	return c;
}

template<typename T>
T vec<T>::dot(const vec<T>& other) const{
	assert(this->size() == other.size());
	return std::inner_product(this->begin(), this->end(), other.begin(), 0.0);
}

/*
vec<T> operator+(double d, const vec<double>& this){
	vec<double>c;
	for (size_t i = 0; i < this->size(); i++)c.push_back(d + this->operator[](i));
	return c;
}
vec<T> operator+(const vec<double>& this, double d){
	vec<double>c;
	for (size_t i = 0; i < this->size(); i++)c.push_back(this->operator[](i) + d);
	return c;
}
vec<T> operator-(double d, const vec<double>& this){
	vec<double>c;
	for (size_t i = 0; i < this->size(); i++)c.push_back(d - this->operator[](i));
	return c;
}
vec<T> operator-(const vec<double>& this, double d){
	vec<double>c;
	for (size_t i = 0; i < this->size(); i++)c.push_back(this->operator[](i) - d);
	return c;
}

vec<T> operator*(double d, vec<double> this){
	for (size_t i = 0; i < this->size(); i++)this->operator[](i) *= d;
	return this;
}
vec<T> operator*(vec<double> this, double d){
	for (size_t i = 0; i < this->size(); i++)this->operator[](i) *= d;
	return this;
}


vec<double> hadamardProduct(const vec<double>& this, const vec<T>& other){
	assert(this->size() == other.size());
	vec<double> c;
	for (size_t i = 0; i < this->size(); i++)
		c.push_back(this->operator[](i) * other[i]);
	return c;
}

template<typename T> vec<T> extractIndices(vec<T> oldvec, vec<size_t> indices){
	vec<T> newvec();
	newvec.reserve(indices.this->size());
	for (size_t ind : indices){
		assert(ind < oldvec.this->size());
		newvec.push_back(oldvec[ind]);
	}
	return newvec;
}
*/
