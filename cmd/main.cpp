#include <iostream>

class Logger {

public:
  void INFO(std::string value) {
    std::cout << "LOG" << " " << value << std::endl;
  };

  void WARNING(std::string value) {
    std::cout << "WARNING" << " " << value << std::endl;
  };

  void ERROR(std::string value) {
    std::cout << "ERROR" << " " << value << std::endl;
  };
};

int main() {
  Logger Log;
  Log.INFO("hello world");
  Log.WARNING("hello world");
  Log.ERROR("hello world");
  return 0;
}
