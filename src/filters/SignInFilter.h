#pragma once

#include <drogon/HttpFilter.h>

using namespace drogon;

class SignInSessionFilter : public HttpFilter<SignInSessionFilter>
{
public:
    void doFilter(const HttpRequestPtr& req, FilterCallback&& filterCallback, FilterChainCallback&& filterChainCallback) override;
};

class SignInTokenFilter : public HttpFilter<SignInTokenFilter>
{
public:
    void doFilter(const HttpRequestPtr& req, FilterCallback&& filterCallback, FilterChainCallback&& filterChainCallback) override;
};