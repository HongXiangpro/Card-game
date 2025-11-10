/**
 * @class JsonUtils
 * @brief 提供静态JSON加载工具函数，封装rapidjson。
 */
#pragma once
#include "json/document.h"
#include "cocos2d.h"

class JsonUtils {
public:
    static bool loadJsonFile(const std::string& filepath, rapidjson::Document& doc);
};
