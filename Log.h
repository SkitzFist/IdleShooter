#pragma once
#include <string>
#include "include/raylib.h"
#include "Vec2.h"

namespace Log{

    static void info(const std::string& msg){
        TraceLog(LOG_INFO, msg.c_str());
    }

    static void newLines(int nrOfLines = 1){
        std::string empty = "";
        for(int i =0; i < nrOfLines; ++i){
            TraceLog(LOG_NONE, empty.c_str());
        }
    }

    static void warning(const std::string& msg){
        TraceLog(LOG_WARNING, msg.c_str());
    }

    static void vector2(const std::string& msg, const Vector2& point){
        std::string m = msg + ": " + std::to_string(point.x) + "|" + std::to_string(point.y);
        info(m);
    }

    template <class T>
    static void vector(const std::string& msg, const Vec2<T>& vec){
        std::string m = msg + ": " + std::to_string(vec.x) + "|" + std::to_string(vec.y);
        info(m);
    }

    static void color(const std::string& msg, const Color& color){
        std::string m = msg + ": " + std::to_string(color.r) + "." + std::to_string(color.g) + "." + std::to_string(color.b) + "." + std::to_string(color.a);
        info(m);
    }
}
