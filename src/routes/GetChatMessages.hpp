#ifndef GET_CHAT_MESSAGES_HPP
#define GET_CHAT_MESSAGES_HPP

#include "AbstractRoute.hpp"

class GetChatMessages : public AbstractRoute
{
public:
    GetChatMessages(ApplicationContext &context);
    ~GetChatMessages();

    void resolve(HttpRequest& req, urls::url_view& params,
                        UserSession& session, send_lambda& send_) override ;
};

#endif
