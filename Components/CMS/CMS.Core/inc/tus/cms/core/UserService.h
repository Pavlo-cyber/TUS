//
// Created by ivan on 16.10.21.
//

#ifndef TUS_USERSERVICE_H
#define TUS_USERSERVICE_H

// gRPC
#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>
#include <grpcpp/server_builder.h>

// std
#include <fstream>
#include <chrono>
#include <string>
#include <sstream>
#include <filesystem>

// grpc
#include "tus/cms/User.grpc.pb.h"

namespace tus::cms::core
{
    class UserServiceImpl : public tus::cms::UserService::Service
    {
    public:
        grpc::Status GetUser(::grpc::ServerContext* context, const ::tus::dom::UInt64* request, ::tus::dom::User* response) override;
        grpc::Status SetUser(::grpc::ServerContext* context, const ::tus::dom::User* request, ::tus::dom::ResponseType* response) override;
    };
}

#endif //TUS_USERSERVICE_H
