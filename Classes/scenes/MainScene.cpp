#include "MainScene.h"

USING_NS_CC;

cocos2d::Scene* MainScene::createScene() {
    return MainScene::create();
}

bool MainScene::init() {
    if (!Scene::init()) return false;

    // 背景色层
    auto background = LayerColor::create(Color4B(60, 120, 60, 255));
    this->addChild(background);

    // 添加 GameView（负责布局）
    _gameView = GameView::create();
    _gameView->setPosition(Vec2(0, 0));
    this->addChild(_gameView);

    auto _controller = new GameController(_gameView);
    _gameView->setController(_controller);

    return true;
}
