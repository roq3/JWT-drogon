# JWT-drogon
JWT implementation for the Drogon framework

It is made as a plugin for the [Drogon](https://github.com/an-tao/drogon) framework.

## Example Usage

For a complete working example of JWT authentication in Drogon, see the [drogon-jwt-test](https://github.com/roq3/drogon-jwt-test) repository. This project demonstrates:

- Login endpoint with JWT token generation
- Protected endpoint with JWT validation
- Complete Drogon application setup with JWT plugin
- Testing examples and management scripts

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
$ cp JWT-drogon/JWT*.* ~/drogon-app/plugins
```

Be aware of add the plugin into the config.json. Set the "name" field to "JWT"

```json
...
"plugins": [
    {
        "name": "JWT",
        "dependencies": [],
        "config": {
            "secret": "your-secret-key"
        }
    }
],
...
```

### Basic Usage in Controllers

```cpp
#include "../plugins/JWT.h"

// In your controller
void YourController::login(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) {
    // Validate credentials...
    
    // Generate JWT token
    JWTimpl jwt("your-secret-key");
    std::map<std::string, std::string> payload = {{"username", "user"}};
    std::string token = jwt.encode(payload);
    
    // Return token
    Json::Value respJson;
    respJson["token"] = token;
    auto resp = HttpResponse::newHttpJsonResponse(respJson);
    callback(resp);
}

void YourController::protectedEndpoint(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) {
    // Check Authorization header
    auto authHeader = req->getHeader("Authorization");
    if (authHeader.empty() || !authHeader.starts_with("Bearer ")) {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(k401Unauthorized);
        resp->setBody("Missing or invalid Authorization header");
        callback(resp);
        return;
    }
    
    std::string token = authHeader.substr(7);
    
    // Validate token
    JWTimpl jwt("your-secret-key");
    try {
        auto decoded = jwt.decode(token);
        // Token is valid, proceed...
        auto resp = HttpResponse::newHttpResponse();
        resp->setBody("Access granted");
        callback(resp);
    } catch (const std::exception& e) {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(k401Unauthorized);
        resp->setBody("Invalid or expired token");
        callback(resp);
    }
}
```

For a complete implementation example, see the [drogon-jwt-test](https://github.com/roq3/drogon-jwt-test) repository.

## Tests

Clone repos to root dir of the project

```bash
$ cd ~/JWT-drogon
$ git clone https://github.com/arun11299/cpp-jwt.git
$ git clone https://github.com/nlohmann/json.git
```

Before run tests

```bash
$ chmod +x test.sh
```

Run base tests

```bash
$ ./test.sh
```

Run unit tests

```bash
$ ./test.sh -t 
```

## API Reference

### JWTimpl Class

- `JWTimpl(std::string secret)` - Constructor with secret key
- `std::string encode(std::map<std::string, std::string> payload)` - Encode JWT token
- `jwt::jwt_object decode(std::string token)` - Decode and validate JWT token

### Usage in Drogon Controllers

The plugin integrates with Drogon's controller system. See the example repository for complete controller implementations.

## Contributing

Contributions are welcome! Please see the [drogon-jwt-test](https://github.com/roq3/drogon-jwt-test) repository for examples of how to extend and test JWT functionality.

## Licence
 [MIT](/LICENSE)