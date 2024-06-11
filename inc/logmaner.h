#pragma once
#if defined(_WIN32) || defined(_WIN64)
#define GOOGLE_GLOG_DLL_DECL
#define GLOG_NO_ABBREVIATED_SEVERITIES
#elif defined(__unix)
#else
static_assert(false, "operation system is not recognized")
#endif

#include <filesystem>

#include "errmaner.h"
#include "singleton.h"

class LogManer : public SingleTon<LogManer> {
 public:
  LogManer() { init(); }
  virtual ~LogManer() { clear(); }

 private:
  void init() {
    namespace fs = std::filesystem;

    fs::create_directories("log/fileparser/info");
    fs::create_directories("log/fileparser/warning");
    fs::create_directories("log/fileparser/error");
    fs::create_directories("log/fileparser/fatal");

    void clear() {}
  };

#define FATAL_LOG LOG(FATAL)
#define ERROR_LOG LOG(ERROR)
#define WARN_LOG LOG(WARNING)
#define INFO_LOG LOG(INFO)

#define WFATAL_LOG(err)                                                 \
  FATAL_LOG << ErrorManer::instance().getErrorCode(ERRCODE::err) << "|" \
            << ErrorManer::instance().getErrorStr(ERRCODE::err) << "|"

#define WERROR_LOG(err)                                                 \
  ERROR_LOG << ErrorManer::instance().getErrorCode(ERRCODE::err) << "|" \
            << ErrorManer::instance().getErrorStr(ERRCODE::err) << "|"

#define WWARN_LOG(err)                                                 \
  WARN_LOG << ErrorManer::instance().getErrorCode(ERRCODE::err) << "|" \
           << ErrorManer::instance().getErrorStr(ERRCODE::err) << "|"

#define WINFO_LOG()                                                            \
  INFO_LOG << ErrorManer::instance().getErrorCode(ERRCODE::ERR_SUCCESS) << "|" \
           << ErrorManer::instance().getErrorStr(ERRCODE::ERR_SUCCESS) << "|"
