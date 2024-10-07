//
// Created by Boris on 05/10/2024.
//

#ifndef BIGINTEGER_H
#define BIGINTEGER_H
#include <string>
#include <vector>


class BigInteger {
public:
    explicit BigInteger(const std::string& value );

    std::vector<char> operator+(BigInteger& other ) const;
    std::vector<char> operator*(BigInteger&  other) const;
    std::vector<char> operator-(const BigInteger&  other)  ;
    friend std::ostream &operator<<(std::ostream &os, const BigInteger &bigInt) ;
    std::vector<char> getDigits() {
         return digits;
    }
    std::string& getValue();

private:
    static std::string addLeadingZeros(size_t size, const std::string& other) ;
    std::string bigValue;
    std::vector<char> digits;
    using type = char ;

};

#endif //BIGINTEGER_H
