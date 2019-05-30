#include "router.h"
#include "response.h"
#include "request.h"

using namespace std;

typedef int (*FN)(int, int);



void showPostPage(Request req, Response res) {
  ostringstream ss;
  ss << "<h1>This is where different posts would go.</h1>"
  "Notice as long as the url starts with /post/ then it will show this page.</br>"
  "<strong>page: </strong>" << req.params["title"] << "</br>"
  "<strong>optional param: </strong>" << req.params["opt"]
  ;
  res.html(ss.str());
}

void fallbackPage(Request req, Response res) {
  ostringstream htmldata;
  htmldata << "<h1 style='color: red'>NOT FOUND</h1><div>This is a fallback route </div><div>Detected route: " << getenv("REQUEST_URI") << "</div>";
  res.html(htmldata.str());
}

int main()
{
    Router::get("/post/:title/?opt", showPostPage);
    Router::raw(".*", fallbackPage);


    return 0;
}
