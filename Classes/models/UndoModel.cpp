#include "UndoModel.h"

UndoModel::UndoModel(CardModel* cardModel) : _cardModel(cardModel) {}

// 记录一次操作
void UndoModel::pushHistory(CardView* card,
    const cocos2d::Vec2& from,
    const cocos2d::Vec2& to,
    PileType fromPile,
    PileType toPile) {
    _history.push_back({ card, from, to, fromPile, toPile });
}

// 撤销上一次操作
void UndoModel::undoLast() {
    if (_history.empty() || _cardModel == nullptr) return;
    auto last = _history.back();
    _history.pop_back();

    // 移动卡牌回原位置
    _cardModel->removeFromPile(last.toPile, last.card);
    _cardModel->addToPile(last.fromPile, last.card);

    last.card->stopAllActions();
    last.card->runAction(cocos2d::MoveTo::create(0.3f, last.from));

    // 调整层级（可选）
    auto parent = last.card->getParent();
    if (parent) {
        int newZ = 1 + static_cast<int>(_cardModel->getPileRef(last.fromPile).size());
        parent->reorderChild(last.card, newZ);
    }
}

// 是否可以撤销
bool UndoModel::canUndo() const {
    return !_history.empty();
}

// 清空历史
void UndoModel::clear() {
    _history.clear();
}
