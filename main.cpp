#include "db/DbUtility.h"
#include <drogon/HttpAppFramework.h>
#include <chrono>

int main(int argc, char *argv[])
{
    db::account::GetAccounts();

    drogon::app()
        // .enableSession(std::chrono::hours(24))
        .addListener("0.0.0.0", 8080)
        .run();

    return 0;
}
