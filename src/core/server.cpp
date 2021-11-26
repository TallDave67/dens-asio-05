#include "server.h"

#include "session.h"

server::server(boost::asio::io_context& io_context, std::uint16_t port)
    : io_context(io_context)
    , acceptor  (io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
{
}

void server::async_accept()
{
    socket.emplace(io_context);

    acceptor.async_accept(*socket, [&] (boost::system::error_code error)
    {
        std::make_shared<session>(std::move(*socket))->start();
        async_accept();
    });
}
