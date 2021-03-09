/**
 * JWTplugin.cc
 *
 * This plugin is for JWT for the Drogon web-framework. Implementation reference from C++ projects from https://jwt.io/. 
 * Please check out https://jwt.io/. 
 
Copyright 2021 roque
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "JWTplugin.h"

/**
 * Initialize and start the plugin
 */
void JWT::initAndStart(const Json::Value &config)
{
    LOG_TRACE << "JWT initialized";
}

/**
 * Shutdown the plugin
 */
void JWT::shutdown() 
{
    LOG_TRACE << "JWT Shutdown";
}

/**
 * Init JWT from passcode
 * 
 * @param string passcode Secret passcode for HS256 algorithm
 * @return JWTimpl
 */
JWTimpl JWT::init( const std::string &passcode)
{
    JWTimpl jwt(passcode);
    
    return jwt;
}