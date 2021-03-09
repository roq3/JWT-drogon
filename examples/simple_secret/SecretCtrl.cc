#include "SecretCtrl.h"
#include "../plugins/JWTplugin.h"

void SecretCtrl::login(std::shared_ptr<Json::Value> &&json,
                std::function<void(const HttpResponsePtr &)> &&callback)
{
    Json::Value ret;

    auto *jwtPtr = drogon::app().getPlugin<JWT>();

    auto jwtClass = jwtPtr->init(
        "super-passcode"                 
    );

    std::map<std::string, std::string> payload;
    payload["iss"] = "some-guy";
    payload["sub"] = "something";
    payload["X-pld"] = "data1";

    // Encode
    auto token = jwtClass.encode(payload);

    // Decode
    jwt::jwt_object decodedData = jwtClass.decode(token);

    if (json) {
        ret["result"] = "ok";
        ret["token"] = token;
        ret["decodedData-payload"] = decodedData.payload().get_claim_value<std::string>("sub");
    } else {
        ret["result"] = "bad";
    }

    auto resp = HttpResponse::newCustomHttpResponse(ret);
    callback(resp);
}