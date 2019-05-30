#ifndef INCLUDE_ROUTER
#define INCLUDE_ROUTER

#include <iostream>
#include <regex>
#include <vector>

#include "Request.h"
#include "Response.h"

using namespace std;

typedef void (*RouterCallback)(Request, Response);

class Router {
 public:
  static vector<string> split(string str, char d);
  static string regex_builder(string route);
  static vector<string> param_builder(string route);
  static void raw(string rgxstr, RouterCallback fn, string paramstr = string());

  static void get(string route, RouterCallback fn);
};

#endif
