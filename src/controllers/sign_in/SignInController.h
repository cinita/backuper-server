#pragma once

#include <drogon/HttpSimpleController.h>
#include "../../utilities/FilterUtility.h"

using namespace drogon;

class SignInController : public HttpSimpleController<SignInController>
{
public:
    void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback) override;
    PATH_LIST_BEGIN
    PATH_ADD_BASIC("/sign_in");
    PATH_LIST_END
};