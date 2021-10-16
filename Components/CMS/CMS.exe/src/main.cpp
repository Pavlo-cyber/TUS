
#include <iostream>
#include "Server.h"


int main(int argc, char** argv)
{
    try
    {
        if(argc != 3)
            throw std::runtime_error("Specify host and port");

        std::string host = argv[1];
        std::uint16_t port = std::stoi(argv[2]);

        tus::cms::server::RunServer(host, port);
    }
    catch(std::exception& e)
    {
        std::cerr << "Exception:" << e.what() << '\n';
    }
    catch(...)
    {
        std::cerr << "Unknown exception occurred\n";
    }
}