#include <iostream>
#include <optional>
#include <boost/algorithm/string.hpp>
using namespace std;

class Base {
public:
    virtual ~Base() = default;

private:
    virtual void member(){}};
class Derived : Base {};

class Polymorphic {
public:
    virtual void member(){}
};

optional<int> test() {
    std::cout << "Before error" << std::endl;
    // Instead of throwing, return a std::nullopt to indicate an error
    return std::nullopt;
}

// Function may throw
int mayThrowFunc() noexcept(false) {
    throw std::runtime_error("Error!");
}

int divide(int a, int b) noexcept(true)
{
try {
    if (b == 0) {
        throw runtime_error("Error: Division by zero");
        cout<<" after throw "<<endl;
    }
}  catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    return -1;
    }
    return a / b;
}


int foo () {
  int v;
    divide(10,0);
    mayThrowFunc();
    try
    {

        Polymorphic*  pb;
        cout<<  typeid(pb).name()<< endl;;  // throws a bad_typeid exception
    }
    catch (std::exception& e)
    {
        std::cerr << "exception caught: " << e.what() << '\n';
    }
    return 0;
}

#include <boost/algorithm/string.hpp>
#include <vector>
#include <string>
using namespace std;
using namespace boost::algorithm;

int main2() {
    std::string s = "Boost C++ and Java Libraries";
    boost::iterator_range<std::string::iterator> r = find_first(s, "C++");
    std::cout << r << '\n';
    r = find_first(s, "xyz");
    std::cout << r << '\n';
    return 0;
}

int main3 () {
  auto result= test();
    if (!result) {
        std::cout << "Error occurred, code executed after test()" << std::endl;
    } else {
        std::cout << "Function returned: " << *result << std::endl;
    }
    //  mayThrowFunc();
  //  divide(10,0);
    return 0;
}
