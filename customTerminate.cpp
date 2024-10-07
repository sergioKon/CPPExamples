#include <iostream>
#include <exception>

void customTerminate() {
    std::cout << "Custom terminate handler executed after throw from noexcept" << std::endl;
    std::abort();  // To actually terminate the program
}

void test() noexcept {
    std::cout << "Inside noexcept function" << std::endl;
    throw std::runtime_error("An error occurred");  // This will call std::terminate
}

int main() {
    std::set_terminate(customTerminate);  // Set custom terminate handler
    test();  // This will call customTerminate
    return 0;
}