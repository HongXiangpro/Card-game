#pragma once
#include "../models/CardModel.h"
#include "../views/GameView.h"
#include "CardController.h"
#include "../configs/models/LevelConfig.h"
#include "../managers/UndoManager.h"

/**
 * @class GameController
 * @brief 游戏主控制器类
 *
 * 管理游戏流程和游戏状态，包括卡牌初始化、界面更新以及撤销操作。
 * 主要职责：
 * 控制游戏的开始与进程
 * 初始化游戏卡牌和模型
 * 处理用户撤销操作
 * 使用场景：
 * 游戏主界面创建后，创建 GameController 来管理游戏逻辑
 * 与 GameView 和 CardController 协作完成游戏交互
 */
class GameController {
public:
    /**
     * @brief 构造函数
     * @param view 游戏界面对象指针
     *
     * 创建 GameController，并绑定对应的 GameView。
     */
    explicit GameController(GameView* view);

    /**
     * @brief 启动游戏
     *
     * 初始化关卡和卡牌，显示界面上的初始状态。
     */
    void startGame();

    /**
     * @brief 撤销上一步操作
     *
     * 调用 UndoManager 执行撤销逻辑。
     */
    void undo();

    /**
     * @brief 初始化卡牌模型
     *
     * 根据当前关卡配置创建 CardModel 对象。
     */
    void initCards();

    

private:
    CardModel _cardmodel;                 ///< 游戏中的卡牌模型
    GameView* _view = nullptr;            ///< 游戏界面对象指针
    CardController* _cardController = nullptr; ///< 卡牌控制器，用于处理卡牌交互逻辑
    LevelConfig _levelConfig;             ///< 当前关卡配置
    UndoManager _undoManager;             ///< 撤销管理器，负责记录操作以便撤销
};
