#pragma once

#include <string>
#include <vector>

namespace db::account
{
    struct Account
    {
        std::string id;
        std::string nickname;
        std::string password;
    };

    using Accounts = std::vector<Account>;

    const Accounts& GetAccounts();

    bool GetAccount(const std::string& id, const std::string& password, Account& account);
} // namespace db::account
