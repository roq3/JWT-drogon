#pragma once
#include <drogon/HttpController.h>

using namespace drogon;

class SecretCtrl : public drogon::HttpController<SecretCtrl>
{
  public:
    METHOD_LIST_BEGIN
    METHOD_ADD(SecretCtrl::login, "/login", Post, Options);
    METHOD_LIST_END

    void login(std::shared_ptr<Json::Value> &&json,
              std::function<void(const HttpResponsePtr &)> &&callback);

  public:
    SecretCtrl()
    {
        LOG_DEBUG << "SecretCtrl constructor!";
    }
};