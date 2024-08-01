#include <iostream>

#include "common.h"
#include "errmaner.h"
#include "logmaner.h"
#include "vermaner.h"

i32_t main(void) {
  ErrorManer::instance();
  VerManer::instance();
  LogManer::instance();

  std::cout << VerManer::instance().getBuildDateTime()
            << " version: " << VerManer::instance().getCurrVer() << std::endl;
  return 0;
}
