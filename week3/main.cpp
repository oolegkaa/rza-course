#include <iostream>
#include "digital_signal.h"
namespace rza_course {
namespace week3 {

void TestDigitalSignal() {
  /*
  // Create a digital signal with initial value 1
  DigitalSignal signal(1);
  std::cout << "Initial value: " << signal.GetValue() << std::endl;
  
  // Change the value
  signal.SetValue(0);
  std::cout << "After setting to 0: " << signal.GetValue() << std::endl;
  
  // Create another signal with default value
  DigitalSignal another_signal;
  std::cout << "Default value: " << another_signal.GetValue() << std::endl; */

  //Toggle
  DigitalSignal signal(1);
  std::cout << "Initial value: " << signal.GetValue() << std::endl;

  signal.ToggleValue(signal.GetValue());
  std::cout << "After first toggle value: " << signal.GetValue() << std::endl;

  signal.ToggleValue(signal.GetValue());
  std::cout << "After second toggle value: " << signal.GetValue() << std::endl;

  std::cout << "Signal is high: " << signal.IsHighValue() << std::endl;

  //Create another signal
  DigitalSignal another_signal(0);
  std::cout << "Another initial signal value: " << another_signal.GetValue() << std::endl;
  
}

}  // namespace week3
}  // namespace rza_course

int main() {
  rza_course::week3::TestDigitalSignal();  
  return 0;
}