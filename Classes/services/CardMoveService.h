#pragma once
#include "cocos2d.h"
#include "../views/CardView.h"
#include "../models/CardModel.h"
#include "../managers/UndoManager.h"

/**
 * @class CardMoveService
 * @brief 封装卡牌移动逻辑（包含从堆移除、添加、动画播放、层级调整、撤销记录）
 * @usage 用于控制层与模型层之间的解耦，所有卡牌移动应通过该服务完成
 */
class CardMoveService {
public:
    /**
     * @brief 构造函数
     * @param model  卡牌模型指针，用于访问各堆的状态
     * @param undoManager 撤销管理器指针，用于记录操作
     */
    CardMoveService(CardModel* model, UndoManager* undoManager);

    /**
     * @brief 执行卡牌的移动操作（包含动画与撤销记录）
     * @param card 要移动的卡牌视图对象
     * @param targetPos 目标位置
     * @param toPile 目标堆类型
     */
    void moveCard(CardView* card, const cocos2d::Vec2& targetPos, PileType toPile);

private:
    CardModel* _cardmodel = nullptr;          ///< 卡牌数据模型
    UndoManager* _undoManager = nullptr;      ///< 撤销操作管理器
};
