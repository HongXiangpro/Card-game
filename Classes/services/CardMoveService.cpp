#include "CardMoveService.h"

USING_NS_CC;

CardMoveService::CardMoveService(CardModel* model, UndoManager* undoManager)
    : _cardmodel(model), _undoManager(undoManager) {
}

void CardMoveService::moveCard(CardView* card, const Vec2& targetPos, PileType toPile) {
    if (!card || !_cardmodel || !_undoManager) return;

    Vec2 fromPos = card->getPosition();
    PileType fromPile = _cardmodel->getPileOf(card);

    // 更新模型：从旧堆移除并加入新堆
    _cardmodel->removeFromPile(fromPile, card);
    _cardmodel->addToPile(toPile, card);

    // 调整渲染层级
    auto parent = card->getParent();
    if (parent) {
        int z = 1 + static_cast<int>(_cardmodel->getPileRef(toPile).size());
        parent->reorderChild(card, z);
    }

    // 执行动画
    card->stopAllActions();
    card->runAction(MoveTo::create(0.3f, targetPos));

    // 记录撤销操作
    _undoManager->recordMove(card, fromPos, targetPos, fromPile, toPile);
}
