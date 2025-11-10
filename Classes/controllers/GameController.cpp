#include "GameController.h"
#include "../configs/loaders/LevelConfigLoader.h"
#include "../services/GameModelFromLevelGenerator.h"


USING_NS_CC;


GameController::GameController(GameView* view)
    : _view(view), _undoManager(&_cardmodel)
{
    if (_view) {
        _cardController = new CardController(&_cardmodel, &_undoManager, _view);
    }
}


void GameController::startGame() {
    _view->hideStartButton();

    std::string path = "res/levels/level1.json";
    _levelConfig = LevelConfigLoader::loadLevelConfig(path);

    // 将加载的配置写入 Model
    GameModelFromLevelGenerator::populateCardModelFromConfig(_levelConfig, _cardmodel);

    initCards();
}

void GameController::initCards() {
    auto cardLayer = _view->getCardLayer();
    cardLayer->setPosition(cocos2d::Vec2(0, 540));

    const int kbase_z = 0;

    // 获取牌区引用
    auto& playField = _cardmodel.getPileRef(PileType::PlayField);
    auto& handPile = _cardmodel.getPileRef(PileType::HandPile);
    auto& topCards = _cardmodel.getPileRef(PileType::TopCards);

    // === 桌面牌 ===
    int zIndex = kbase_z;
    for (auto& c : playField) {
        cardLayer->addChild(c, zIndex++);
        _view->addCardTouchListener(c, false); // false 表示桌面牌
    }

    // === 手牌区 ===
    zIndex = kbase_z;
    for (auto& c : handPile) {
        cardLayer->addChild(c, zIndex++);
        _view->addCardTouchListener(c, true);  // true 表示手牌
    }

    // === 顶部牌（初始化最后一张手牌为 topCard） ===
    CardView* topCard = _cardmodel.getCurrentTopCard();
    if (topCard) {
        cardLayer->addChild(topCard, kbase_z + static_cast<int>(topCards.size()));
    }

    // 点击回调
    _view->setCardClickCallback(
        [this](CardView* card, bool isHand) {
            if (isHand)
                _cardController->handleHandCardClick(card);
            else
                _cardController->handlePlayFieldCardClick(card);
        }
    );
}


void GameController::undo() {
    _undoManager.undo();
}
