#ifndef RZA_COURSE_WEEK5_GPIO_SIMULATOR_H_
#define RZA_COURSE_WEEK5_GPIO_SIMULATOR_H_

#include <string>
#include <fstream>
#include <vector>

namespace rza_course {
namespace week5 {

// Class for simulating GPIO input/output operations using text files
class GpioSimulator {
 public:
  // Constructor that sets up the GPIO pin path
  explicit GpioSimulator(const std::string& pin_path);
  
  // Destructor
  ~GpioSimulator();
  
  // Read the current state of the GPIO pin
  int32_t ReadState() const;
  
  // Write a state to the GPIO pin
  bool WriteState(int32_t state);
  
  // Read multiple states from GPIO pins
  std::vector<int32_t> ReadMultipleStates(size_t count) const;
  
 private:
  std::string pin_path_;
  mutable std::fstream pin_file_;
  
  // Helper function to open the pin file for reading/writing
  bool OpenPinFile() const;
};

}  // namespace week5
}  // namespace rza_course

#endif  // RZA_COURSE_WEEK5_GPIO_SIMULATOR_H_