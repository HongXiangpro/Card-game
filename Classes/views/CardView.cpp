#include "views/CardView.h"


USING_NS_CC;

CardView* CardView::create(int faceIndex, CardSuitType suit, bool isBig) {
    auto card = new (std::nothrow) CardView();
    if (card && card->init(faceIndex, suit, isBig)) {
        card->autorelease();
        return card;
    }
    CC_SAFE_DELETE(card);
    return nullptr;
}

bool CardView::init(int faceIndex, CardSuitType suit, bool isBig) {
    if (!Node::init()) {
        return false;
    }

    // 保存状态
    _faceIndex = faceIndex;
    _suit = suit;
    _isBig = isBig;

    // === 背景 ===
    _background = Sprite::create(CardResConfig::getCardBackground());
    _background->setScale(1.8f); 
    _background->setScaleY(1.5f);
    this->addChild(_background);

    // === 数字 ===
    std::string numPath = CardResConfig::getNumberImage(static_cast<CardFaceType>(faceIndex), suit, isBig);
    _number = Sprite::create(numPath);
    _number->setPosition(Vec2(-120, _background->getContentSize().height - 120));
    _number->setScale(0.5f);
    this->addChild(_number);

    // === 花色 ===
    std::string suitPath = CardResConfig::getSuitImage(suit);
    _suitSprite = Sprite::create(suitPath);
    _suitSprite->setPosition(Vec2(0, _background->getContentSize().height - 250));
    _suitSprite->setScale(3.5f);
    this->addChild(_suitSprite);

    this->setContentSize(_background->getContentSize() * 1.8f);
    this->setScale(1.0f);

    return true;
}


