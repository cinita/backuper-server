#pragma once

#include <json/json.h>

inline Json::Value GenerateFailedJsonResponse(const std::string& message)
{
    Json::Value root;
    Json::Value data;
    root["code"] = -1;
    root["message"] = message;
    root["data"] = data;
    return root;
}