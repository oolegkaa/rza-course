#include <iostream>
#include <vector>
#include <fstream>
#include "gpio_simulator.h"

namespace rza_course {
namespace week5 {

void TestGpioSimulator() {
  // Create a GPIO simulator for pin "/dev/gpio_0"
  GpioSimulator gpio("/dev/gpio_0");
  
  // Write some states to simulate GPIO output
  std::cout << "Writing GPIO states..." << std::endl;
  gpio.WriteState(1);
  gpio.WriteState(0);
  gpio.WriteState(1);
  
  // Read the current state
  int32_t current_state = gpio.ReadState();
  std::cout << "Current GPIO state: " << current_state << std::endl;
  
  // Simulate reading multiple GPIO states
  std::vector<int32_t> multi_states = gpio.ReadMultipleStates(5);
  std::cout << "Multiple GPIO states: ";
  for (const auto& state : multi_states) {
    std::cout << state << " ";
  }
  std::cout << std::endl;
  
  // Create simulated GPIO files for testing
  std::ofstream file1("/dev/gpio_0_sim_0");
  file1 << "1" << std::endl;
  file1.close();
  
  std::ofstream file2("/dev/gpio_0_sim_1");
  file2 << "0" << std::endl;
  file2.close();
  
  std::cout << "Simulated GPIO files created for testing." << std::endl;
}

}  // namespace week5
}  // namespace rza_course

int main() {
  rza_course::week5::TestGpioSimulator();
  return 0;
}