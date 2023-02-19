#include "GetOwnPosts.hpp"
#include <entities/message/MessageDao.hpp>

GetOwnPosts::GetOwnPosts(ApplicationContext &context) : AbstractRoute(context)
{
}

GetOwnPosts::~GetOwnPosts()
{
}

void    GetOwnPosts::resolve(http::request<http::string_body>& req, urls::url_view& params,
                        UserSession& session, send_lambda& send_)
{
    MessageDao &dao = getContext().getMessageDao();
    int offset = getIntFromUrlView(params, "offset");
    
    vector<Message> posts = dao.getUserPosts(session.getUserID().get(), offset);
    json::array postsJson;
    for (auto &post : posts)
    {
        postsJson.emplace_back(post.getJsonObject());
    }

    json::object payload;
    payload.emplace("status", true);
    payload.emplace("data", postsJson);

    http::response<http::string_body> res{http::status::ok, req.version()};
    res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
    res.set(http::field::content_type, "application/json");
    set_cors(res);
    res.keep_alive(req.keep_alive());
    res.body() = json::serialize(payload);
    res.prepare_payload();
    send_(std::move(res));
}