/*

RangeValue::RangeValue(){
    value = 0;
}

RangeValue::RangeValue(int n){
if(n < -1000 || n > 1000){ throw RangeValueException();}
   else  value = n;
}

int RangeValue::getValue() const{
    return value;
}

RangeValue operator+(const RangeValue& a, const RangeValue& b){
	return RangeValue{a.getValue() + b.getValue()};
}

RangeValue operator-(const RangeValue& a, const RangeValue& b){
       return RangeValue{a.getValue() - b.getValue()};
}

RangeValue operator*(const RangeValue& a, const RangeValue& b){
       return RangeValue{a.getValue() * b.getValue()};
}

bool operator>(const RangeValue& a, const RangeValue& b){
        return a.getValue() > b.getValue();
}

bool operator<(const RangeValue& a, const RangeValue& b){
       return a.getValue() < b.getValue();
}

bool operator==(const RangeValue& a, const RangeValue& b){
        return a.getValue() == b.getValue();
}

bool operator!=(const RangeValue& a, const RangeValue& b){
        return a.getValue() != b.getValue();
}

RangeValue& RangeValue::operator+=(const RangeValue& a){
      this->value += a.getValue();
      return *this;
}

RangeValue& RangeValue::operator*=(const RangeValue& a){

      this->value *= a.getValue();
      return *this;
}

RangeValue& RangeValue::operator-=(const RangeValue& a){

      this->value -= a.getValue();
      return *this;
}
*/