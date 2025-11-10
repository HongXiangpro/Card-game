#include "GameModelFromLevelGenerator.h"
#include "cocos2d.h"
USING_NS_CC;

void GameModelFromLevelGenerator::populateCardModelFromConfig(const LevelConfig& cfg, CardModel& outModel) {
    // 获取牌区引用，存到局部变量
    auto& playField = outModel.getPileRef(PileType::PlayField);
    auto& handPile = outModel.getPileRef(PileType::HandPile);
    auto& topCards = outModel.getPileRef(PileType::TopCards);

    // 清空牌区
    playField.clear();
    handPile.clear();
    topCards.clear();

    // 桌面牌
    for (const auto& cardCfg : cfg.Playfield) {
        auto card = CardView::create(
            cardCfg.CardFace,
            static_cast<CardSuitType>(cardCfg.CardSuit),
            true
        );
        card->setPosition(cardCfg.Position);
        playField.push_back(card);
    }

    // 手牌区（带偏移）
    float offset = 250.0f;
    for (const auto& cardCfg : cfg.Stack) {
        auto card = CardView::create(
            cardCfg.CardFace,
            static_cast<CardSuitType>(cardCfg.CardSuit),
            true
        );
        cocos2d::Vec2 adjustedPos = cardCfg.Position;
        adjustedPos.x += offset;
        card->setPosition(adjustedPos);
        offset += 20.0f;
        handPile.push_back(card);
    }

    // 初始 topCard（将最后一张手牌移入 topCards）
    if (!handPile.empty()) {
        CardView* lastHand = handPile.back();
        handPile.pop_back();
        lastHand->setPosition(cocos2d::Vec2(750, 0));
        topCards.push_back(lastHand);
    }
}
