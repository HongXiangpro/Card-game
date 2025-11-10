#pragma once
#include "cocos2d.h"
#include "../models/CardModel.h"
#include "../views/GameView.h"
#include "../managers/UndoManager.h"
#include "services/CardMoveService.h"

/**
 * @class CardController
 * @brief 卡牌控制器，负责处理卡牌的用户交互逻辑
 *
 * 主要职责：
 * 响应手牌区和桌面区的卡牌点击事件
 * 调用 UndoManager 执行撤销操作
 * 使用场景：
 * 与 CardModel、GameView 和 UndoManager 协作，实现卡牌游戏的控制逻辑
 * 模块职责：
 * 处理卡牌交互逻辑，不负责渲染或数据存储
 */
class CardController {
public:
    /**
     * @brief 构造函数
     * @param model 指向卡牌数据模型，用于获取和修改卡牌状态
     * @param undoManager 指向撤销管理器，用于记录可撤销操作
     * @param view 指向游戏视图，用于更新界面
     */
    CardController(CardModel* model, UndoManager* undoManager, GameView* view);

    /**
     * @brief 处理手牌区卡牌点击事件
     * @param card 被点击的卡牌视图
     */
    void handleHandCardClick(CardView* card);

    /**
     * @brief 处理桌面区卡牌点击事件
     * @param card 被点击的卡牌视图
     */
    void handlePlayFieldCardClick(CardView* card);

    /**
     * @brief 撤销上一次操作
     */
    void undoLast();

private:
    CardModel* _cardmodel;                      ///< 指向卡牌数据模型
    UndoManager* _undoManager;                  ///< 指向撤销管理器
    GameView* _view;                            ///< 指向游戏视图
    CardMoveService* _moveService = nullptr;    ///< 指向卡牌移动服务
};
