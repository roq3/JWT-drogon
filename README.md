# JWT-drogon
JWT implementation for the Drogon framework

## Plugin required dependencies

* cpp-jwt https://github.com/arun11299/cpp-jwt
* json https://github.com/nlohmann/json

Clone repos to root dir of your drogon app

```bash
$ cd ~/drogon-app
$ git clone https://github.com/arun11299/cpp-jwt.git
$ git clone https://github.com/nlohmann/json.git
```

Add some lines in CMakeLists.txt of your dragon app

```txt
...
find_package(Drogon CONFIG REQUIRED)

add_subdirectory(cpp-jwt)
add_subdirectory(json)

target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon cpp-jwt::cpp-jwt nlohmann_json::nlohmann_json)
...
```

## Usage
Download to the plugin directory of the target drogon app, E.g. ~/drogon-app/plugins

```bash
$ git clone https://github.com/roq3/JWT-drogon.git
$ cp JWT-drogon/JWT.* ~/drogon-app/plugins
```

Be aware of add the plugin into the config.json. Set the "name" field to "JWT"

```json
...
"plugins": [
    ...
    {
        "name": "JWT",
        "dependencies": [],
        "config": {
        }
    }
    ...
],
...
```

Add the reference header and get the plugin from the app(), E.g. 

```c++
...
#include "../plugins/JWT.h"
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

Build the app

## Licence
* Feel free to use