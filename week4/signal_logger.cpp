#include "signal_logger.h"
#include <iostream>
#include <vector>

namespace rza_course {
namespace week4 {

SignalLogger::SignalLogger(const std::string& filename) : filename_(filename) {
  log_file_.open(filename_);
  if (!log_file_.is_open()) {
    std::cerr << "Error: Could not open file " << filename_ << std::endl;
  }
}

SignalLogger::~SignalLogger() {
  if (log_file_.is_open()) {
    log_file_.close();
  }
}

void SignalLogger::LogSignalState(int32_t state) {
  if (log_file_.is_open()) {
    log_file_ << state << std::endl;
  } else {
    std::cerr << "Error: Log file is not open" << std::endl;
  }
}

void SignalLogger::LogSignalStates(const std::vector<int32_t>& states) {
  if (log_file_.is_open()) {
    for (const auto& state : states) {
      log_file_ << state << std::endl;
    }
  } else {
    std::cerr << "Error: Log file is not open" << std::endl;
  }
}

}  // namespace week4
}  // namespace rza_course