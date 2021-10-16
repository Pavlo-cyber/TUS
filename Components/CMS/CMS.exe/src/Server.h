//
// Created by ivan on 16.10.21.
//

#ifndef TUS_SERVER_H
#define TUS_SERVER_H
#include <string>

namespace tus::cms::server
{
    void RunServer(const std::string& host, uint16_t port);
}

#endif //TUS_SERVER_H
