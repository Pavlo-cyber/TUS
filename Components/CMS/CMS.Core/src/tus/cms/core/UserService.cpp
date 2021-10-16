//
// Created by ivan on 16.10.21.
//

#include "tus/cms/core/UserService.h"
#include "google/protobuf/util/json_util.h"

grpc::Status tus::cms::core::UserServiceImpl::GetUser(grpc::ServerContext *context, const tus::dom::UInt64 *request,
                                                      tus::dom::User *MyUser)
{
    try
    {
        std::string output;
        grpc::protobuf::json::JsonOptions options;
        options.add_whitespace = true;
        grpc::protobuf::json::MessageToJsonString(*request, &output, options);
        std::cout << "RequestJson: " << output << '\n';

        MyUser->set_id(47ll);
        MyUser->set_name("Petro Wold Dmitrovich");

        return grpc::Status::OK;
    }
    catch(const std::exception& e)
    {
        return {grpc::StatusCode::CANCELLED, "Error occurred:" + std::string(e.what())};
    }
    catch(...)
    {
        return {grpc::StatusCode::CANCELLED, "Unknown error"};
    }
}

grpc::Status tus::cms::core::UserServiceImpl::SetUser(grpc::ServerContext *context, const tus::dom::User *request,
                                                      tus::dom::ResponseType *response)
{
    try
    {
        std::string output;
        grpc::protobuf::json::JsonOptions options;
        options.add_whitespace = true;
        grpc::protobuf::json::MessageToJsonString(*request, &output, options);
        std::cout << "RequestJson: " << output << '\n';

        // probably update user in db;
        response->set_msg("User " + request->name() + " was updated successfully");
        response->set_statuscode(tus::dom::StatusCode::Success);

        return grpc::Status::OK;
    }
    catch(const std::exception& e)
    {
        return {grpc::StatusCode::CANCELLED, "Error occurred:" + std::string(e.what())};
    }
    catch(...)
    {
        return {grpc::StatusCode::CANCELLED, "Unknown error"};
    }
}
