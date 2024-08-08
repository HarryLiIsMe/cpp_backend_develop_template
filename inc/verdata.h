#pragma once

#include <string>

#include "common.h"

#define VER_TYPE const std::string
#define VER_DEF inline VER_TYPE

VER_TYPE VER_TOSTR(i32_t i) { return std::to_string(i); }

VER_DEF VER_0 = VER_TOSTR(001);
VER_DEF VER_1 = VER_TOSTR(002);
VER_DEF VER_2 = VER_TOSTR(101);
VER_DEF VER_CURR = VER_2;
