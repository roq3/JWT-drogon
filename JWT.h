/**
 * JWT.h
 *
 * This plugin is for JWT for the Drogon web-framework. Implementation reference from C++ projects from https://jwt.io/. 
 * Please check out https://jwt.io/. 
 
Copyright 2021 roque
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#pragma once

#include "jwt/jwt.hpp"

/**
 * Class JWT 
 * Simple implementation of JWT
 */
class JWTimpl
{
    public:
        std::string passcode;
        
        /**
         * Constrtuctor
         * 
         * @param std::string x Secret passcode for HS256 algorithm
         */
        JWTimpl(std::string x)
        {
            passcode = x;
        }

        /**
         * Constrtuctor
         */ 
        ~JWTimpl(){}

        /**
         * Encode payload
         * 
         * @param map payload Payload data
         * @return std::string Encoded token string
         */
        std::string encode(std::map<std::string, std::string> payload);

        /**
         * Decode payload
         * 
         * @param string payload Encoded token string
         * @return auto
         */
        jwt::jwt_object decode(std::string token);
};