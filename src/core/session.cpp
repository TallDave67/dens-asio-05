#include "session.h"

#include <iostream>

session::session(boost::asio::ip::tcp::socket&& socket)
    : socket(std::move(socket))
{
}

session::~session()
{
    std::cout << "session::~session() : the shared ptr holding onto us went out of scope.  when we go away so does the connection to the client" << std::endl;
}

void session::start()
{
    std::cout << "session::start()" << std::endl;
    boost::asio::async_read_until(socket, streambuf, '\n', [self = shared_from_this()] (boost::system::error_code error, std::size_t bytes_transferred)
    {
        std::cout << std::istream(&self->streambuf).rdbuf();
    });
}
