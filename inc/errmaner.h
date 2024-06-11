#pragma once
#include <exception>
#include <map>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "errordata.h"
#include "singleton.h"

struct GlobalError : std::runtime_error {
  GlobalError(ERRCODE errcode, std::string message)
      : m_errocde(errcode), std::runtime_error(message) {}
  ERRCODE get_code() { return m_errocde; }
  std::string get_message() { return this->runtime_error::what(); };
  std::string to_string() {
    return "error code: " + std::to_string(static_cast<ui64_t>(m_errocde)) +
           " error message: " + this->runtime_error::what();
  }

 private:
  ERRCODE m_errocde;
};

class ErrorManer : public SingleTon<ErrorManer> {
 public:
  ErrorManer() {
    setErrorStr(ERRCODE::ERR_SUCCESS, "successful");
    setErrorStr(ERRCODE::ERR_FAILED, "failed");
    setErrorStr(ERRCODE::ERR_VER_NOT_FOUND, "version is not found");
    setErrorStr(ERRCODE::ERR_STD_EXCEPTION, "std exception capture");
    setErrorStr(ERRCODE::ERR_UNKNOWN1, "unknown exception 1 capture");
  }

  std::string getErrorStr(ERRCODE errcode) {
    auto it = m_errormap.find(errcode);
    if (it == m_errormap.end())
      throw std::runtime_error("error code get failed, error code :" +
                               std::to_string(static_cast<ui64_t>(errcode)) +
                               "\n");
    return it->second;
  }
  ui64_t getErrorCode(ERRCODE errcode) {
    auto it = m_errormap.find(errcode);
    if (it == m_errormap.end())
      throw std::runtime_error("error code get failed, error code :" +
                               std::to_string(static_cast<ui64_t>(errcode)) +
                               "\n");
    return static_cast<ui64_t>(errcode);
  }
  void setErrorStr(ERRCODE errcode, std::string errorstr) {
    auto it = m_errormap.insert({errcode, errorstr});
    if (!it.second) {
      throw std::runtime_error("error manager init failed, error code :" +
                               std::to_string(static_cast<ui64_t>(errcode)) +
                               "\n");
    }
  }

 private:
  std::unordered_map<ERRCODE, std::string> m_errormap;
};

#define THROW_GERR(errcode) \
  throw GlobalError(errcode, ErrorManer::instance().getErrorStr(errcode));

#define WTHROW_GERR(err) THROW_GERR(ERRCODE::err)
