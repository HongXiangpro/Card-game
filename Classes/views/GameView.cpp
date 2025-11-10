#include "GameView.h"
#include "../controllers/GameController.h"

USING_NS_CC;

bool GameView::init() {
    if (!Node::init()) return false;

    // 背景
    auto bg = LayerColor::create(Color4B(128, 0, 128, 255), 1080, 2080);
    this->addChild(bg);

    // 卡层
    _cardLayer = Layer::create();
    this->addChild(_cardLayer, 1);

    // 开始按钮
    _startButton = MenuItemImage::create("res/ui/start_normal.png", "res/ui/start_pressed.png",
        [this](Ref*) { if (_controller) _controller->startGame(); });
    _startButton->setPosition(Vec2(540, 1000));

    // 回退按钮
    _undoButton = MenuItemImage::create("res/ui/undo_normal.png", "res/ui/undo_pressed.png",
        [this](Ref*) { if (_controller) _controller->undo(); });
    _undoButton->setPosition(Vec2(940, 200));

    _menu = Menu::create(_startButton, _undoButton, nullptr);
    _menu->setPosition(Vec2::ZERO);
    this->addChild(_menu);

    return true;
}

void GameView::hideStartButton() {
    if (_startButton) _startButton->setVisible(false);
}

void GameView::setCardClickCallback(const std::function<void(CardView*, bool)>& cb) {
    _onCardClick = cb;
}

void GameView::addCardTouchListener(CardView* card, bool isHand) {
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true); // 防止穿透

    listener->onTouchBegan = [this, card, isHand](cocos2d::Touch* t, cocos2d::Event*) {
        // 将触摸点转换到卡牌本地坐标
        cocos2d::Vec2 localPos = card->convertToNodeSpace(t->getLocation());

        // === 手动定义检测区域 ===
        // Rect(x偏移, y偏移, 宽度, 高度)
        // 例如调整为卡牌稍微向左上偏移的区域
        cocos2d::Size cardSize = card->getContentSize();
        float scaleX = card->getScaleX();
        float scaleY = card->getScaleY();

        // 手动调整矩形，可以修改 dx/dy 来移动检测框
        float dx = -170.0f;  // 向左偏移
        float dy = -230.0f;  // 向下偏移
        float w = cardSize.width * scaleX;   
        float h = cardSize.height * scaleY - 65;

        cocos2d::Rect customRect(dx, dy, w, h);

        if (customRect.containsPoint(localPos)) {
            if (_onCardClick) _onCardClick(card, isHand);
            return true;
        }

        return false;
        };

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, card);
}