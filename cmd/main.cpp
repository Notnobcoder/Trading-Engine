#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <sstream>
#include <thread>

class Logger {
private:
  std::ofstream logFile;
  std::mutex logMutex;

  Logger(const std::string &filename) {
    logFile.open(filename, std::ios::app);
    if (!logFile.is_open()) {
      throw std::runtime_error("Failed to open log file");
    }
  }

  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;

  std::string getTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");

    return ss.str();
  }

  void writeLog(const std::string &level, const std::string &message) {
    std::lock_guard<std::mutex> lock(logMutex);

    std::string logEntry = "[" + getTimestamp() +
                           "] "
                           "[" +
                           level + "] " + message;

    std::cout << logEntry << std::endl;
    logFile << logEntry << std::endl;
  }

public:
  static Logger &getInstance(const std::string &filename = "app.log") {
    static Logger instance(filename);
    return instance;
  }

  void info(const std::string &message) { writeLog("INFO", message); }

  void warning(const std::string &message) { writeLog("WARNING", message); }

  void error(const std::string &message) { writeLog("ERROR", message); }

  ~Logger() {
    if (logFile.is_open())
      logFile.close();
  }
};

void worker(int id) {
  auto &logger = Logger::getInstance();

  logger.info("Worker " + std::to_string(id) + " started");
  logger.warning("Worker " + std::to_string(id) + " warning example");
  logger.error("Worker " + std::to_string(id) + " error example");
}

int main() {

  std::thread t1(worker, 1);
  std::thread t2(worker, 2);
  std::thread t3(worker, 3);
  std::thread t4(worker, 4);
  std::thread t5(worker, 5);
  std::thread t6(worker, 6);

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  t6.join();

  return 0;
}
