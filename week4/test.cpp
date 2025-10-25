#include <iostream>

int main() {
    std::cout << "Версия стандарта C++: " << __cplusplus << std::endl;
    
    // Более детальная проверка
    #if __cplusplus == 202302L
        std::cout << "C++23" << std::endl;
    #elif __cplusplus == 202002L
        std::cout << "C++20" << std::endl;
    #elif __cplusplus == 201703L
        std::cout << "C++17" << std::endl;
    #elif __cplusplus == 201402L
        std::cout << "C++14" << std::endl;
    #elif __cplusplus == 201103L
        std::cout << "C++11" << std::endl;
    #else
        std::cout << "До C++11" << std::endl;
    #endif
    
    return 0;
}