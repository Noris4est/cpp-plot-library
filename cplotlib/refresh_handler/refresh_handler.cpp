#include "refresh_handler.hpp"

IRefreshHandler::IRefreshHandler()
{

}

void IRefreshHandler::register_refresh_handler(std::function<void(void)> handler)
{
    this->handler = handler;
}

void IRefreshHandler::handle()
{
    handler();
}