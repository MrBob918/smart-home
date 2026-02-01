#include <boost/asio.hpp>
#include <boost/beast/http.hpp>
#include <iostream>
//test123
namespace net  = boost::asio;
namespace http = boost::beast::http;

int main()
{
    net::io_context ioc;

    http::request<http::string_body> req;
    req.method(http::verb::get);
    req.target("/");
    req.version(11);

    std::cout << "Beast is working, HTTP version = "
              << req.version() << "\n";
}
