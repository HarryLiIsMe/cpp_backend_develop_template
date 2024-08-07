#pragma once

#include "common.h"

// version 1
enum class ERRCODE : ui64_t {
  ERR_SUCCESS = 0,
  ERR_FAILED = 1,
  ERR_VER_NOT_FOUND = 2,
  ERR_STD_EXCEPTION = 3,
  ERR_UNKNOWN1 = 4,
};
