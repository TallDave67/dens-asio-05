#pragma once

#include <optional>
#include <boost/asio.hpp>

class server
{
public:
    server(boost::asio::io_context& io_context, std::uint16_t port);
    void async_accept();

private:
    boost::asio::io_context& io_context;
    boost::asio::ip::tcp::acceptor acceptor;
    std::optional<boost::asio::ip::tcp::socket> socket;
};