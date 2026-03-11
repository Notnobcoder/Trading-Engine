#include <chrono>
#include <format>
#include <iostream>
#include <string_view>

class Logger {
public:
  void INFO(std::string_view value) { log("LOG", value); }
  void WARNING(std::string_view value) { log("WARNING", value); }
  void ERROR(std::string_view value) { log("ERROR", value); }

private:
  void log(std::string_view level, std::string_view msg) {
    auto now = std::chrono::system_clock::now();

    std::cout << std::format("[{}] [{}] {}\n", now, level, msg);
  }
};

void Logg() {
  Logger Log;
  Log.INFO("hello world");
  Log.WARNING("hello world");
  Log.ERROR("hello world");
}

int main() {
  Logg();
  return 0;
}
