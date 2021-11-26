#include "server.h"

int main()
{
    boost::asio::io_context io_context;
    std::uint16_t port = 15001;
    server srv(io_context, port);
    srv.async_accept();
    io_context.run();
    return 0;
}