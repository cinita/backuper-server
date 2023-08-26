#include "DbUtility.h"
#include <json/json.h>
#include <mutex>
#include <fstream>
#include <iostream>

namespace db::account
{
    const Accounts &GetAccounts()
    {
        static Accounts g_accounts{};
        static std::once_flag g_flag;

        std::call_once(g_flag,
                       [&]()
                       {
                           g_accounts.clear();

                           Json::Value accounts;
                           std::ifstream ifs("../accounts.json", std::ifstream::binary);
                           ifs >> accounts;

                           for (auto it = accounts.begin(); it != accounts.end(); ++it)
                           {
                               auto &account = *it;
                               g_accounts.push_back({account["id"].asString(),
                                                     account["nickname"].asString(),
                                                     account["password"].asString()});
                           }
                       });

        return g_accounts;
    }

    bool GetAccount(const std::string &id, const std::string &password, Account &account)
    {
        for (auto &_account : GetAccounts())
        {
            if (_account.id == id && _account.password == password)
            {
                account = _account;
                return true;
            }
        }

        return false;
    }
} // namespace db::account
