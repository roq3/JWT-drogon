# JWT-drogon Examples

Add the reference header and get the plugin from the app(), E.g. 

```c++
...
#include "../plugins/JWTplugin.h"
...

//Inside function, E.g. A controller function.
...
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

std:string someSub = decodedData.payload().get_claim_value<std::string>("sub"); // return sub as string (someSub will be "something")
```