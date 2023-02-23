#ifndef GET_CHAT_LIST_HPP
#define GET_CHAT_LIST_HPP

#include "AbstractRoute.hpp"

class GetChatList : public AbstractRoute
{
public:
    GetChatList(ApplicationContext &context);
    ~GetChatList();

    void resolve(HttpRequest& req, urls::url_view& params,
                        UserSession& session, send_lambda& send_) override ;
};

#endif
