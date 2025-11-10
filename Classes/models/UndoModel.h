#pragma once
#include "cocos2d.h"
#include "../views/CardView.h"
#include "CardModel.h"
#include <vector>

/**
 * @struct MoveHistory
 * @brief 保存一次卡牌移动操作的历史记录
 *
 * 描述一次移动的完整信息，包括移动的卡牌、起始和目标位置，以及起始堆和目标堆类型。
 * 使用场景：
 * UndoModel 在执行撤销操作时，用于恢复卡牌到上一次状态
 * 模块职责：
 * 单一职责：只负责存储一次移动的信息
 */
struct MoveHistory {
    CardView* card;       ///< 被移动的卡牌指针
    cocos2d::Vec2 from;   ///< 起始位置
    cocos2d::Vec2 to;     ///< 目标位置
    PileType fromPile;    ///< 起始堆类型
    PileType toPile;      ///< 目标堆类型
};

/**
 * @class UndoModel
 * @brief 卡牌操作撤销管理器
 *
 * 管理卡牌操作的历史记录，实现撤销功能。
 * 主要职责：
 * 记录每次卡牌移动历史
 * 提供撤销操作接口
 * 提供历史状态查询和清空功能
 * 使用场景：
 * 在游戏中允许玩家撤销操作
 * 模块职责：
 * 管理撤销历史，不涉及具体的游戏逻辑
 */
class UndoModel {
public:
    /**
     * @brief 构造函数
     * @param cardModel 当前操作的卡牌模型对象，用于执行撤销恢复操作
     */
    explicit UndoModel(CardModel* cardModel);

    /**
     * @brief 记录一次操作历史
     * @param card 被移动的卡牌指针
     * @param from 起始位置
     * @param to 目标位置
     * @param fromPile 起始堆类型
     * @param toPile 目标堆类型
     */
    void pushHistory(CardView* card,
        const cocos2d::Vec2& from,
        const cocos2d::Vec2& to,
        PileType fromPile,
        PileType toPile);

    /**
     * @brief 撤销上一次操作
     *
     * 将卡牌恢复到上一次状态，并从历史记录中移除该记录。
     */
    void undoLast();

    /**
     * @brief 是否可以执行撤销操作
     * @return 如果有可撤销的历史，返回 true；否则返回 false
     */
    bool canUndo() const;

    /**
     * @brief 清空所有历史记录
     *
     * 通常在新关卡开始或重置游戏时调用。
     */
    void clear();

private:
    CardModel* _cardModel = nullptr;          ///< 操作的卡牌模型指针
    std::vector<MoveHistory> _history;       ///< 保存所有移动操作历史记录
};
