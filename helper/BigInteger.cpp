//
// Created by Boris on 05/10/2024.
//

#include "BigInteger.h"

#include <iostream>
#include <string>
using namespace  std;


    BigInteger::BigInteger(const std::string& value ): bigValue(value){
        this->digits.assign(value.begin(), value.end());
    }

    string BigInteger::addLeadingZeros(size_t size, const string& other) {
        string second(size+other.length(),' ');
        int count = other.size();
        int align = size-count;
        for(int i=0;i< align; i++) {
            second[i]= '0';
        }

        for(int i=size-count, j=0; i < size; i++ , j++) {
            second[i]= other.at(j);
        }
        return second;
    }

    vector<char> BigInteger::operator+(BigInteger& other ) const {
        int sum=0;
        const size_t size = bigValue.length();
        string second= addLeadingZeros(size,  other.getValue());
        vector<char> result(size);
        int remainder=0;
        for(int i=size-1; i > -1;i--) {
            sum= bigValue[i] - '0';
            sum+= second[i] - '0' ;
            result[i]=sum%10+remainder;
            remainder= sum/10;
        }
        return result;
    }

    vector<BigInteger::type> BigInteger::operator*(BigInteger&  other) const {
        return ( vector<char>()) ;
    }

    vector<char> BigInteger::operator-(const BigInteger&  other)  {
         vector<char> dest = other.digits;
         vector<char> res ( digits.size(),0);
         for(size_t i=digits.size()-1 , j= dest.size()-1; i>0; i--, j--) {
             int  diff= (digits[i]) - dest[j] ;
             if (diff < 0) {
                 diff+=10;
                 digits[i-1]-=1;
             }
              res.at(i) = diff;
         }
         return res ;
    }



    string&  BigInteger::getValue() {
        return bigValue;
    }

    std::ostream&  operator<<(std::ostream &os, const BigInteger &bigInt) {
        string value= bigInt.bigValue;
        for (auto it = bigInt.bigValue.rbegin(); it != bigInt.bigValue.rend(); ++it) {
            //         os << static_cast<int>(*it);
        }
        /*  for (int i=0;i< value.size(); i++) {
              os <<static_cast<int>(value[i]);
          }
          */return os;

    }


