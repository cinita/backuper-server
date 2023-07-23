#include "SignIn.h"
#include "../../db/DbUtility.h"
#include <drogon/drogon.h>
#include <map>

namespace
{
    std::map<std::string, db::account::Account> g_activeAccounts;

    inline std::string GenerateUserToken(const std::string &prefix)
    {
        return drogon::utils::getMd5(prefix + std::to_string(std::chrono::system_clock::now().time_since_epoch().count()));
    }

} // namespace

void TestCtrl::asyncHandleHttpRequest(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    const auto &userName = req->getHeader("User-Id");
    const auto &userPassword = req->getHeader("User-Password");

    db::account::Account account;
    const auto hasAccount = db::account::GetAccount(userName, userPassword, account);

    Json::Value root;
    Json::Value data;
    if (hasAccount)
    {
        const auto token = GenerateUserToken(account.id);
        for (auto it = g_activeAccounts.begin(); it != g_activeAccounts.end(); ++it)
        {
            if (it->second.id == account.id)
            {
                g_activeAccounts.erase(it);
                break;
            }
        }
        g_activeAccounts[token] = account;

        root["code"] = 0;
        root["message"] = "success";
        data["user_token"] = token;
        root["data"] = data;
    }
    else
    {
        root["code"] = -1;
        root["message"] = "failed";
        root["data"] = data;
    }

    callback(HttpResponse::newHttpJsonResponse(std::move(root)));
}