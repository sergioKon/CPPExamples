#include <iostream>
#include <string>
#include <climits>
#include <algorithm>  // For std::reverse
#include <string.h>
#include <vector>

using  namespace  std;

class BigInteger {
public:
    explicit BigInteger(const string& value ): bigValue(value){
       this->digits.assign(value.begin(), value.end());
    }

    static string addLeadingZeros(size_t size, const string& other) {
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

    vector<int> operator+(BigInteger other ) const {
        int sum=0;
        const size_t size = bigValue.length();
        string second= addLeadingZeros(size,  other.getValue());

       vector<int> result(size);
       int remainder=0;
       for(int i=size-1; i > -1;i--) {
          sum= bigValue[i] - '0';
          sum+= second[i] - '0' ;
          result[i]=sum%10+remainder;
          remainder= sum/10;
       }
        return result;
    }
    string& getValue() {
        return bigValue;
    }
    friend std::ostream &operator<<(std::ostream &os, const BigInteger &bigInt) {
        string value= bigInt.bigValue;
       for (auto it = bigInt.bigValue.rbegin(); it != bigInt.bigValue.rend(); ++it) {
   //         os << static_cast<int>(*it);
        }
      /*  for (int i=0;i< value.size(); i++) {
            os <<static_cast<int>(value[i]);
        }
        */return os;

    }

private:
    string bigValue;
     vector<int> digits;
};



int main(int argc, char* argv[] ) {
    string str = "This is a sample string";

    size_t start=0;
    size_t end=0;
    vector<int> pos{};
    pos.push_back(0);
   do {
    end= str.find(" ",start);
        pos.push_back(end);
        cout<< str.substr(start, end-start)<< " " << endl;
        start=end+1;
    }
    while(end!=-1);

    pos.pop_back();
    for (auto it = pos.begin(); it != pos.end(); ++it ) {
        size_t wide= *(it+1) -*it;
        std::cout << str.substr(*it, wide) << std::endl;
    }
    exit(2);

    int index = 0;
 //   string result=   add("123456789012345678901234567890", "987654321098765432109876543210");
  //  cout << result <<endl;

    if(argc > 1 ) {
        index = std::stoi(argv[1]);
    }
    BigInteger big1("1123");

    const BigInteger big2("457");
    vector<int> vec= big1 + big2;
    ranges::for_each(vec,
                     [](int x) { cout << x << " "; });
    cout << endl;
    return 0;
    int first=0, second=1;
    long long current=1;
    for(int i=2; i< index+1;i++) {
           // 0 1 1 2 3 5 8 13 21
         current = first + second;   // 5 +8 =13
         first=second;
         second = current;
    }
     cout << current << endl;
}
