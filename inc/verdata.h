#pragma once
#include <string>

#include "common.h"

#define VER_TYPE std::string
#define VER_DEF inline VER_TYPE

inline std::string VER_TOSTR(i32_t i) { return std::to_string(i); }

VER_DEF VER_0 = VER_TOSTR(0);
VER_DEF VER_1 = VER_TOSTR(1);
VER_DEF VER_CURR = VER_1;
