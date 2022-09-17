#ifndef IREFRESHHANDLER
#define IREFRESHHANDLER

#include <functional>

class IRefreshHandler
{
public:
    IRefreshHandler();
    void register_refresh_handler(std::function<void(void)> handler);
    virtual void handle();
private:
    std::function<void(void)> handler;
};
#endif // IREFRESHHANDLER