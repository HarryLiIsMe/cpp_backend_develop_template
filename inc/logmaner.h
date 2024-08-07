#pragma once

#include <iostream>
#include <sstream>

#include "errmaner.h"
#include "singleton.h"

class LogManer : public SingleTon<LogManer> {
 public:
  LogManer() { init(); }
  virtual ~LogManer() { clear(); }

 private:
  void init() {}
  void clear() {}

 public:
  enum class LogLevelType {
    DisabledLevel = 0b0,
    InfoLevel = 0b1,
    WarnLevel = 0b10,
    ErrorLevel = 0b100,
    FatalLevel = 0b1000,
    DebugLevel = 0b10000
  };

 public:
  void setLogLevel(u8_t levels) { m_levels = levels; }

  u8_t getLogLevel() { return m_levels; }

  void setLogFormat() {}

  void setLogDest() {}

  template <typename... Args>
  void log(LogLevelType level, ERRCODE err, const std::string& format_str,
           Args&&... args) {
    std::string msg_str = format(format_str, std::forward<Args>(args)...);

    if (ERRCODE::ERR_SUCCESS != err) {
      std::string err_str = format("errcode: {}, errmsg: {}",
                                   ErrorManer::instance().getErrorCode(err),
                                   ErrorManer::instance().getErrorStr(err));
    }
  }

  template <typename... Args>
  void debug(const std::string& format_str, const Args&... args) {
    log(LogLevelType::WarnLevel, ERRCODE::ERR_SUCCESS, format_str,
        std::forward<Args>(args)...);
  }

  template <typename... Args>
  void info(const std::string& format_str, const Args&... args) {
    log(LogLevelType::WarnLevel, ERRCODE::ERR_SUCCESS, format_str,
        std::forward<Args>(args)...);
  }

  template <typename... Args>
  void warn(ERRCODE err, const std::string& format_str, const Args&... args) {
    log(LogLevelType::WarnLevel, err, format_str, std::forward<Args>(args)...);
  }

  template <typename... Args>
  void error(ERRCODE err, const std::string& format_str, const Args&... args) {
    log(LogLevelType::ErrorLevel, err, format_str, std::forward<Args>(args)...);
  }

  template <typename... Args>
  void fatal(ERRCODE err, const std::string& format_str, const Args&... args) {
    log(LogLevelType::FatalLevel, err, format_str, std::forward<Args>(args)...);
  }

 private:
  template <typename... Args>
  std::string format(const std::string& format_str, Args&&... args) {
    std::ostringstream oss;
    format_impl(oss, format_str, std::forward<Args>(args)...);
    return oss.str();
  }

  void format_impl(std::ostringstream& oss, const std::string& format_str) {
    oss << format_str;
  }

  template <typename T, typename... Args>
  void format_impl(std::ostringstream& oss, const std::string& format_str,
                   T&& value, Args&&... args) {
    std::size_t pos = format_str.find("{}");
    if (pos != std::string::npos) {
      oss << format_str.substr(0, pos) << std::forward<T>(value);
      format_impl(oss, format_str.substr(pos + 2), std::forward<Args>(args)...);
    } else {
      oss << format_str;
    }
  }

 private:
  u8_t m_levels;
};
