#include "JsonUtils.h"
#include "platform/CCFileUtils.h"

using namespace cocos2d;
using namespace rapidjson;

bool JsonUtils::loadJsonFile(const std::string& filepath, Document& doc) {
    std::string fullPath = FileUtils::getInstance()->fullPathForFilename(filepath);
    std::string content = FileUtils::getInstance()->getStringFromFile(fullPath);
    if (content.empty()) return false;
    doc.Parse(content.c_str());
    return !doc.HasParseError();
}
