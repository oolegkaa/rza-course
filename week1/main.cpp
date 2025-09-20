#include <iostream>

namespace rza_course {
namespace week1 {

// Print hello world message to console
void PrintHelloWorld() {
  std::cout << "Hello, world!" << std::endl;
}

}  // namespace week1
}  // namespace rza_course

int main() {
  rza_course::week1::PrintHelloWorld();
  return 0;
}