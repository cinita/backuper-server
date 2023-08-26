#include <drogon/HttpAppFramework.h>
#include <chrono>

using namespace drogon;

int main(int argc, char* argv[])
{
    app()
        .enableSession(std::chrono::days(7))
        .addListener("0.0.0.0", 8080)
        .run();

    return 0;
}
