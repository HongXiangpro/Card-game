#include "LevelConfigLoader.h"
#include "cocos2d.h"
using namespace cocos2d;
using namespace rapidjson;

LevelConfig LevelConfigLoader::loadLevelConfig(const std::string& filePath) {
    LevelConfig config;
    std::string jsonStr = FileUtils::getInstance()->getStringFromFile(filePath);
    Document doc;
    doc.Parse(jsonStr.c_str());

    if (doc.HasParseError()) return config;
    for (auto& item : doc["Playfield"].GetArray()) {
        CardConfig card;
        card.CardFace = item["CardFace"].GetInt();
        card.CardSuit = item["CardSuit"].GetInt();
        card.Position = Vec2(item["Position"]["x"].GetFloat(),
            item["Position"]["y"].GetFloat());
        config.Playfield.push_back(card);
    }
    for (auto& item : doc["Stack"].GetArray()) {
        CardConfig card;
        card.CardFace = item["CardFace"].GetInt();
        card.CardSuit = item["CardSuit"].GetInt();
        card.Position = Vec2(item["Position"]["x"].GetFloat(),
            item["Position"]["y"].GetFloat());
        config.Stack.push_back(card);
    }
    return config;
}