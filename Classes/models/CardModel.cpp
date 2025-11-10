#include "CardModel.h"

// 获取当前顶部牌
CardView* CardModel::getCurrentTopCard() const {
    if (_topCards.empty()) return nullptr;
    return _topCards.back();
}

// 根据卡牌查找其所属牌区
PileType CardModel::getPileOf(CardView* card) const {
    if (std::find(_playField.begin(), _playField.end(), card) != _playField.end())
        return PileType::PlayField;
    if (std::find(_handPile.begin(), _handPile.end(), card) != _handPile.end())
        return PileType::HandPile;
    if (std::find(_topCards.begin(), _topCards.end(), card) != _topCards.end())
        return PileType::TopCards;
    return PileType::PlayField; // 默认返回一个值
}

// 从一个牌区移除卡牌
void CardModel::removeFromPile(PileType pile, CardView* card) {
    auto& vec = getPileRef(pile);
    vec.erase(std::remove(vec.begin(), vec.end(), card), vec.end());
}

// 向一个牌区添加卡牌
void CardModel::addToPile(PileType pile, CardView* card) {
    auto& vec = getPileRef(pile);
    vec.push_back(card);
}

// 返回牌区引用
std::vector<CardView*>& CardModel::getPileRef(PileType pile) {
    switch (pile) {
    case PileType::PlayField: return _playField;
    case PileType::HandPile: return _handPile;
    case PileType::TopCards: return _topCards;
    }
    return _playField; // 不应触发
}
