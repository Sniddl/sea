#include <iostream>
#include <sstream>
#include <map>

using namespace std;

class Response
{
public:
    void set_header(string name, string value)
    {
        _headers[name] = value;
    }
    void send(string data)
    {
        for (auto const &[name, value] : _headers)
        {
            cout << name << ": " << value << endl;
        }
        cout << endl;
        cout << data << endl;
        exit(0);
    }

private:
    map<string, string> _headers = {{"content-type", "text/plain"}};
};

// class Response {
// };

int main()
{
    // cout << "content-type: text/plain" << endl << "server: Sniddl Sea" << endl << endl;
    // cout << "hello world!" << endl;
    // cout << "Route: " << getenv("REQUEST_URI") << endl;
    ostringstream html;
    Response res;

    html << "<h1>Hello World</h1>"
         << "<strong>Path: </strong>" << getenv("REQUEST_URI");

    res.set_header("content-type", "text/html");
    res.send(html.str());
    return 0;
}