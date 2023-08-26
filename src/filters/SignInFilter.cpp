#include "SignInFilter.h"
#include "../utilities/FilterUtility.h"
#include "../utilities/ResponseUtility.h"
#include "../AccountManager.h"

void SignInSessionFilter::doFilter(const HttpRequestPtr& req, FilterCallback&& filterCallback, FilterChainCallback&& filterChainCallback)
{
    auto isSignedIn = req->session()->getOptional<bool>("is_signed_in").value_or(false);
    if (isSignedIn) {
        filterChainCallback();
    }
    else {
        AccountManager::GetInstance().
        auto resp = HttpResponse::newHttpJsonResponse(GenerateFailedJsonResponse("Sign in required, re-sign in please"));
        filterCallback(resp);
    }
}

void SignInTokenFilter::doFilter(const HttpRequestPtr& req, FilterCallback&& filterCallback, FilterChainCallback&& filterChainCallback)
{
    auto token = req->getHeader("Backuper-Token");
    // auto isValidToken = backuper::IsActiveAccount(token);
    auto isValidToken = false;
    if (isValidToken) {
        filterChainCallback();
    }
    else {
        auto resp = HttpResponse::newHttpJsonResponse(GenerateFailedJsonResponse("Invalid token"));
        filterCallback(resp);
    }
}