#ifndef INCLUDE_REQUEST
#define INCLUDE_REQUEST

#include <map>

using namespace std;

class Request
{
public:
  Request();
  map<string, string> params;
};

#endif
