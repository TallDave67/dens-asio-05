#pragma once

#include <memory>
#include <boost/asio.hpp>

class session : public std::enable_shared_from_this<session>
{
public:
    session(boost::asio::ip::tcp::socket&& socket);
    ~session();
    
    void start();

private:
    boost::asio::ip::tcp::socket socket;
    boost::asio::streambuf streambuf;
};