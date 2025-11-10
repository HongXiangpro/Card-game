#pragma once
#include "cocos2d.h"
#include "views/GameView.h"
#include "../controllers/GameController.h"

/**
 * @class MainScene
 * @brief 游戏主场景入口类
 *
 * MainScene 负责初始化游戏场景和管理游戏界面的主要入口。
 * 主要职责：
 * 创建并初始化游戏场景
 * 持有 GameView 和 GameController 对象
 * 使用场景：
 * 游戏启动后创建的主场景，用于显示游戏界面并交互
 * 模块设计：
 * 管理场景生命周期和主控对象，不处理具体游戏逻辑
 */
class MainScene : public cocos2d::Scene {
public:
    /**
     * @brief 创建并返回 MainScene 场景对象
     * @return cocos2d::Scene* 新创建的场景指针
     */
    static cocos2d::Scene* createScene();

    /**
     * @brief 初始化场景
     * @return bool 初始化成功返回 true，否则返回 false
     */
    virtual bool init() override;

    /**
     * @brief 宏定义，用于创建 MainScene 对象
     */
    CREATE_FUNC(MainScene);

private:
    GameView* _gameView = nullptr;        ///< 游戏界面视图对象，用于显示卡牌和动画
    GameController* _controller = nullptr;///< 游戏控制器对象，管理游戏逻辑和用户输入
};
