#pragma once
#include <string>
#include <type_traits>

// #include "boost/lexical_cast/try_lexical_convert.hpp"
#include "errmaner.h"
#include "singleton.h"
#include "verdata.h"

using namespace std::literals::string_literals;

class VerManer : public SingleTon<VerManer> {
 public:
  enum class EVER_COMP {
    // version equal
    EVEREQUAL = 0,
    // version large
    EVERLARGER = 1,
    // version less
    EVERLESS = -1
  };
  std::string getStrCurrVer() { return std::string("VER_").append(VER_CURR); }

  VER_TYPE getCurrVer() { return VER_CURR; }

  EVER_COMP compareVer(VER_TYPE lver, VER_TYPE rver) {
    i32_t ilver, irver;
    // bool res = boost::conversion::detail::try_lexical_convert(lver, ilver);
    // res = boost::conversion::detail::try_lexical_convert(rver, irver);
    // if (!res) THROW_GERR(ERRCODE::ERR_VER_NOT_FOUND);

    if (ilver == irver) return EVER_COMP::EVEREQUAL;
    return ilver > irver ? EVER_COMP::EVERLARGER : EVER_COMP::EVERLESS;
  }

  std::string getBuildDateTime() {
    return std::string("build date: ")
        .append(__DATE__)
        .append(" time: ")
        .append(__TIME__);
  }
};
