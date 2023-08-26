#pragma once

#include <drogon/HttpSimpleController.h>

#define PATH_ADD_BASIC(path, ...) registerSelf__(path, {Post, "drogon::IntranetIpFilter", "SignInSessionFilter", "SignInTokenFilter", __VA_ARGS__})


