#pragma once
#include "error.h"

template <typename T, T Bottom=-1000, T Up=1000>
class RangeValue{
private:
    T value;
    
public:
RangeValue(): value(0) {}
	

RangeValue(T n){
    
if(n < Bottom || n > Up){throw RangeValueException();}
   else  value = n;
}
T getValue() const {return value;
};


 RangeValue& operator+=(const RangeValue<T, Bottom, Up>& a);
 RangeValue& operator*=(const RangeValue<T, Bottom, Up>& a);
 RangeValue& operator-=(const RangeValue<T, Bottom, Up>& a);


};

template <typename T, T Bottom, T Up>
RangeValue<T, Bottom, Up> operator+(const RangeValue<T, Bottom, Up>& a, const RangeValue<T, Bottom, Up>& b){
	return RangeValue<T, Bottom, Up>(a.getValue() + b.getValue());
}

template <typename T, T Bottom, T Up>
RangeValue<T, Bottom, Up> operator-(const RangeValue<T, Bottom, Up>& a, const RangeValue<T, Bottom, Up>& b){
       return RangeValue<T, Bottom, Up>(a.getValue() - b.getValue());
}

template <typename T, T Bottom, T Up>
RangeValue<T, Bottom, Up>operator*(const RangeValue<T, Bottom, Up>& a, const RangeValue<T, Bottom, Up>& b){
       return RangeValue<T, Bottom, Up>(a.getValue() * b.getValue());
}

template <typename T, T Bottom, T Up>
bool operator>(const RangeValue<T, Bottom, Up>& a, const RangeValue<T, Bottom, Up>& b){
        return a.getValue() > b.getValue();
}

template <typename T, T Bottom, T Up>
bool operator<(const RangeValue<T, Bottom, Up>& a, const RangeValue<T, Bottom, Up>& b){
       return a.getValue() < b.getValue();
}

template <typename T, T Bottom, T Up>
bool operator==(const RangeValue<T, Bottom, Up>& a, const RangeValue<T, Bottom, Up>& b){
        return a.getValue() == b.getValue();
}

template <typename T, T Bottom, T Up>
bool operator!=(const RangeValue<T, Bottom, Up>& a, const RangeValue<T, Bottom, Up>& b){
        return a.getValue() != b.getValue();
}
template <typename T, T Bottom, T Up>
RangeValue<T, Bottom, Up>& RangeValue<T, Bottom, Up>::operator*=(const RangeValue<T, Bottom, Up>& a){
      this->value *= a.getValue();
      return *this;
}

template<typename T, T Bottom, T Up>
RangeValue<T, Bottom, Up>& RangeValue<T, Bottom, Up>::operator+=(const RangeValue<T, Bottom, Up>& a){
      this->value += a.getValue();
      return *this;
}



template <typename T, T Bottom, T Up>
RangeValue<T, Bottom, Up>& RangeValue<T,Bottom, Up>::operator-=(const RangeValue<T, Bottom, Up>& a){
      this->value -= a.getValue();
      return *this;
}
