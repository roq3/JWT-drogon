# JWT-drogon
JWT implementation for the Drogon framework

It is made as a plugin for the [Drogon](https://github.com/an-tao/drogon) framework.

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
        }
    }
],
...
```

Build the app as usual

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

## Licence
* Feel free to use