#include "router.h"

vector<string> Router::split(string str, char d)
{
    stringstream ss(str);
    string tmpstr;
    vector<string> res;
    while (getline(ss, tmpstr, d)) {
        res.push_back(tmpstr);
    }
    return res;
}

void Router::raw(string rgxstr, RouterCallback fn, string paramstr)
{
    // required = ([^/]+)/?
    // optional = ([^/]+)?/?
    string uri = getenv("REQUEST_URI");
    std::regex rgx(rgxstr);
    std::smatch matches;
    if (std::regex_search(uri, matches, rgx)) {
        Request req;
        vector<string> params = Router::param_builder(paramstr);
        for (size_t i = 1;
             i < matches.size() && params.size() == matches.size() - 1; ++i) {
            req.params[params[i - 1]] = matches[i].str();
        }
        Response res;
        fn(req, res);
        exit(0);
    }
}

string Router::regex_builder(string route)
{
    ostringstream rgx;
    vector<string> tokens = split(route, '/');
    for (unsigned i = 0; i < tokens.size(); i++) {
        if (tokens[i][0] == ':' || tokens[i][0] == '*') {
            rgx << "([^/]+)/";
        } else if (tokens[i][0] == '?') {
            rgx << "?([^/]+)?/";
        } else {
            rgx << tokens[i] << "/";
        }
    }
    rgx << "?";
    return rgx.str();
}

vector<string> Router::param_builder(string route)
{
    vector<string> tokens = split(route, '/');
    vector<string> params;
    for (unsigned i = 0; i < tokens.size(); i++) {
        if (tokens[i][0] == ':' || tokens[i][0] == '?' || tokens[i][0] == '*') {
            tokens[i].erase(0, 1);
            params.push_back(tokens[i]);
        }
    }
    return params;
}

void Router::get(string route, RouterCallback fn)
{
  Router::raw(Router::regex_builder(route), fn, route);
}
