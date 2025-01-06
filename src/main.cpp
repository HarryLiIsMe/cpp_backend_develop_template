#include <cstdlib>
#include <iostream>

#include "common.h"
#include "dotenv.h"
#include "errmaner.h"
#include "logmaner.h"
#include "vermaner.h"

using namespace std;
using std::cout, std::endl, std::string, std::getenv, std::exit;

i32_t main(void) {
  ErrorManer::instance();
  VerManer::instance();
  LogManer::instance();

  env_load(".", false);
  const char* project_name = getenv("PROJECT_NAME");
  if (NULL == project_name) {
    cout << "env load failed!!!" << endl;
    exit(-1);
  }

  cout << "hello world " << project_name << endl;
  cout << VerManer::instance().getBuildDateTime()
       << " version: " << VerManer::instance().getCurrVer() << endl;
  return 0;
}
