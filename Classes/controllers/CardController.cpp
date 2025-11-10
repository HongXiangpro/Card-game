#include "CardController.h"
#include "cocos2d.h"

USING_NS_CC;

CardController::CardController(CardModel* model, UndoManager* undoManager, GameView* view)
    : _cardmodel(model), _undoManager(undoManager), _view(view) {
    _moveService = new CardMoveService(model, undoManager);
}


void CardController::handleHandCardClick(CardView* card) {
    if (!card) return;
    _moveService->moveCard(card, Vec2(750, 0), PileType::TopCards);
}

void CardController::handlePlayFieldCardClick(CardView* card) {
    if (!card) return;
    CardView* topCard = _cardmodel->getCurrentTopCard();
    if (!topCard) return;

    int diff = (abs(card->getFaceIndex() - topCard->getFaceIndex()))%11;
    if (diff == 1) {
        _moveService->moveCard(card, Vec2(750, 0), PileType::TopCards);
    }
}

void CardController::undoLast() {
    _undoManager->undo();
}
