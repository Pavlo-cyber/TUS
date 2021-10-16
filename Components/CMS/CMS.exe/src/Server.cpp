//
// Created by ivan on 16.10.21.
//

#include "Server.h"
#include <utility>
#include <iostream>
#include "tus/cms/core/UserService.h"

namespace tus::cms::server::impl
{
    class Server
    {
    private:
        std::unique_ptr<grpc::Server> m_Server;
        std::string m_Host;
        std::uint16_t m_Port;
    public:
        Server(std::string host, uint16_t port);
//     TODO: make server configurable from command line and config file
        void Run();
    };
}

tus::cms::server::impl::Server::Server(std::string  host, uint16_t port) :
    m_Host(std::move(host)), m_Port(port)
{
}

void tus::cms::server::impl::Server::Run()
{
    std::string server_address(this->m_Host + ":" + std::to_string(this->m_Port));
    tus::cms::core::UserServiceImpl service;
    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    m_Server = std::unique_ptr<grpc::Server>(builder.BuildAndStart());
    std::cout << "server listening on " << server_address << '\n';
    m_Server->Wait();
}

void tus::cms::server::RunServer(const std::string& host, uint16_t port)
{
    tus::cms::server::impl::Server MyServer(host, port);
    MyServer.Run();
}