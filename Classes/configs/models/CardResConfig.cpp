#include "CardResConfig.h"
#include <map>
#include <string>


USING_NS_CC;

std::map<std::pair<CardSuitType, CardFaceType>, CardResItem> CardResConfig::_cardResMap;

void CardResConfig::init()
{
    _cardResMap.clear();

    const std::string ksuits[] = { "clubs", "diamonds", "hearts", "spades" };
    const std::string kfaces[] = {
        "A", "2", "3", "4", "5", "6", "7",
        "8", "9", "10", "J", "Q", "K"
    };

    for (int s = CST_CLUBS; s < CST_NUM_CARD_SUIT_TYPES; ++s)
    {
        for (int f = CFT_ACE; f < CFT_NUM_CARD_FACE_TYPES; ++f)
        {
            CardResItem item;
            item.frontTexture = StringUtils::format("res/res/number/%s_%s.png", ksuits[s].c_str(), kfaces[f].c_str());
            item.backTexture = "res/res/card_general.png"; 
            _cardResMap[{ (CardSuitType)s, (CardFaceType)f }] = item;
        }
    }
}

const CardResItem& CardResConfig::getCardRes(CardSuitType suit, CardFaceType face)
{
    static CardResItem empty = { "", ""};
    auto key = std::make_pair(suit, face);
    auto it = _cardResMap.find(key);
    if (it != _cardResMap.end())
        return it->second;
    return empty;
}


Node* CardResConfig::createCardNode(CardSuitType suit, CardFaceType face, bool isBig)
{
    auto res = getCardRes(suit, face);
    auto node = Node::create();

    // 背景
    auto bg = Sprite::create(res.backTexture);
    bg->setScale(isBig ? 1.8f : 1.0f);
    node->addChild(bg);

    // 数字
    auto number = Sprite::create(res.frontTexture);
    number->setAnchorPoint(Vec2(0, 1));
    number->setPosition(Vec2(-120, bg->getContentSize().height - 90));
    number->setScale(isBig ? 0.5f : 0.3f);
    node->addChild(number);

    // 花色小图标暂时复用frontTexture
    auto suitSprit = Sprite::create(res.frontTexture);
    suitSprit->setAnchorPoint(Vec2(0, 0));
    suitSprit->setPosition(Vec2(-50, bg->getContentSize().height - 350));
    suitSprit->setScale(isBig ? 3.5f : 2.0f);
    node->addChild(suitSprit);

    node->setContentSize(bg->getContentSize() * (isBig ? 1.8f : 1.0f));
    node->setAnchorPoint(Vec2(0.5f, 0.5f));
    node->setScale(0.9f);

    return node;
}