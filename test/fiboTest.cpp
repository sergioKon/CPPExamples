//
// Created by Boris on 05/10/2024.
//

#include <iostream>
#include <string>
#include <vector>
#include  "../helper/Biginteger.h"
#include <cassert>
#include <algorithm>
#include <iomanip>


template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vector){
  for (auto element : vector) {
    if(std::is_same_v<T, char>) {
      element =  element+ '0';
    }
       os << element;
  }
    os<<std::endl;
  return os;
}

#include <numeric>
int main() {

  BigInteger first("152");
  BigInteger second("36");
  std::vector<char> res= first+second;
  if( res == std::vector{'1','8','8'}) {
    std::cout <<"Equal";
  }
  else {
     std::cout <<"UnEqual\n";
  }
  auto temp= std::vector<char>{'1','8','8'};
  std::cout<< res << std::endl;
  assert( res ==  temp);
  std::cout<< res << std::endl;

  res= first-second;
  temp= std::vector{'0','1','6'};
  assert(res== temp );
  std::cout<< res << std::endl;
  return 0;
}
