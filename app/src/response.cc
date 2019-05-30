#include "response.h"

Response::Response() {
  _statuscode = 0;
  _headers = {{"content-type", "text/plain"}};
}

void Response::set_header(string name, string value) {
  _headers[name] = value;
}

void Response::send(string data) {
  if (_statuscode > 0) {
    cout << "Status: " << _statuscode << endl;
  }
  for (auto const& [name, value] : _headers) {
    cout << name << ": " << value << endl;
  }
  cout << endl;
  cout << data << endl;
  exit(0);
}

void Response::html(string data) {
  set_header("content-type", "text/html");
  send(data);
}

void Response::status(int code) {
  _statuscode = code;
}
