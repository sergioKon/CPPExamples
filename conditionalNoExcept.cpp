#include <iostream>
#include <type_traits>
using namespace  std;

// A generic function that conditionally uses noexcept based on the type's move constructor
template<typename T>
void foo(T&& t) noexcept(std::is_nothrow_move_constructible_v<T>) {
    T local = std::forward<T>(t);  // This operation might throw, depending on the type
    std::cout << "foo called with noexcept: " << noexcept(local = t) << std::endl;
};

struct A {

    A() {

    }
    A(A&&) throw() {

    }
};

int main(int argc , char*argv[]) {

    int x = 5;
    foo(std::move(x));  // int is noexcept
    
   // std::string s = "test";
    A a{};
    foo(std::move(a));  // std::string's move constructor may throw
}
