#ifndef INCLUDE_RESPONSE
#define INCLUDE_RESPONSE

#include <iostream>
#include <map>
#include <regex>
#include <functional>
#include <vector>

using namespace std;

class Response {
public:
    Response();
    void set_header(string name, string value);
    void send(string data);
    void html(string data);
    void status(int code);

private:
    map<string, string> _headers;
    int _statuscode;
};

#endif
