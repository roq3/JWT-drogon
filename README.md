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
$ cp JWT-drogon/JWT*.* ~/drogon-app/plugins
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

Build the app

## Tests

Clone repos to third-party dir of the plugin

```bash
$ cd ~/JWT-drogon/third-party
$ git clone https://github.com/arun11299/cpp-jwt.git
$ git clone https://github.com/nlohmann/json.git
```

Run Tests

```bash
$ chmod +x test.sh
$ ./test.sh
```

Run Unit Tests

```bash
$ chmod +x test.sh
$ ./test.sh -t 
```

## Licence
* Feel free to use