#include "refresh_handler.hpp"

IRefreshHandler::IRefreshHandler()
{
    handler = [](){};
}

void IRefreshHandler::register_refresh_handler(std::function<void(void)> handler)
{
    this->handler = handler;
}

void IRefreshHandler::handle()
{
    handler();
}