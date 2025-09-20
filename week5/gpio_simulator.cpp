#include "gpio_simulator.h"
#include <iostream>
#include <vector>
#include <sstream>

namespace rza_course {
namespace week5 {

GpioSimulator::GpioSimulator(const std::string& pin_path) : pin_path_(pin_path) {}

GpioSimulator::~GpioSimulator() {
  if (pin_file_.is_open()) {
    pin_file_.close();
  }
}

int32_t GpioSimulator::ReadState() const {
  if (!OpenPinFile()) {
    return -1;  // Error
  }
  
  int32_t state = -1;
  pin_file_ >> state;
  pin_file_.close();
  
  return state;
}

bool GpioSimulator::WriteState(int32_t state) {
  std::ofstream output_file(pin_path_);
  if (!output_file.is_open()) {
    return false;
  }
  
  output_file << state << std::endl;
  output_file.close();
  
  return true;
}

std::vector<int32_t> GpioSimulator::ReadMultipleStates(size_t count) const {
  std::vector<int32_t> states;
  
  for (size_t i = 0; i < count; ++i) {
    // Simulate reading from different GPIO pins
    std::string simulated_pin_path = pin_path_ + "_sim_" + std::to_string(i);
    
    std::ifstream input_file(simulated_pin_path);
    if (input_file.is_open()) {
      int32_t state = -1;
      input_file >> state;
      input_file.close();
      states.push_back(state);
    } else {
      states.push_back(-1);  // Error
    }
  }
  
  return states;
}

bool GpioSimulator::OpenPinFile() const {
  pin_file_.open(pin_path_);
  if (!pin_file_.is_open()) {
    return false;
  }
  return true;
}

}  // namespace week5
}  // namespace rza_course