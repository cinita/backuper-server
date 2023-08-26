#pragma once

#include <string>
#include <map>

class AccountManager
{
public:
    static AccountManager& GetInstance()
    {
        static AccountManager g_instance;
        return g_instance;
    }

    bool IsActiveAccount(const std::string& token) const
    {
        return m_activeAccounts.find(token) != m_activeAccounts.end();
    }

    void AddActiveAccount(const std::string& token, const std::string& userId)
    {
        m_activeAccounts[token] = userId;
    }

    void RemoveActiveAccount(const std::string& token)
    {
        m_activeAccounts.erase(token);
    }

public:
    AccountManager(const AccountManager&) = delete;
    AccountManager& operator=(const AccountManager&) = delete;

private:
    AccountManager() {}

private:
    std::map<std::string/*token*/, std::string/*user_id*/> m_activeAccounts{};
};