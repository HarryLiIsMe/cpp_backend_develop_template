#pragma once

using i8_t = char;
using i16_t = short;
using i32_t = int;
using i64_t = long long;
using u8_t = unsigned char;
using u16_t = unsigned short;
using u32_t = unsigned int;
using u64_t = unsigned long long;
using f32_t = float;
using f64_t = double;

#ifndef _WIN32
#ifndef WIN32
#ifndef _WIN64
#ifndef WIN64
#define __declspec(dllexport)
#endif
#endif
#endif
#endif
