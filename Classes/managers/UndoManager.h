#pragma once
#include "../models/UndoModel.h"
#include <functional>

/**
 * @class UndoManager
 * @brief 管理卡牌操作的撤销功能
 *
 * 主要职责：
 * 记录每次卡牌移动操作
 * 提供撤销操作接口
 * 提供查询是否可撤销和清空操作历史接口
 * 可设置撤销回调通知外部更新UI
 * 使用场景：
 * 在卡牌游戏中，玩家操作后可以撤销上一步移动
 * 与控制器或视图结合，保证界面状态与操作历史一致
 */
class UndoManager {
public:
    /**
     * @brief 构造函数
     * @param model 指向与该管理器关联的卡牌模型
     */
    explicit UndoManager(CardModel* model)
        : _undoModel(model) {
    }

    /**
     * @brief 记录一次卡牌移动操作
     * @param card 移动的卡牌
     * @param from 移动前的位置
     * @param to 移动后的位置
     * @param fromPile 移动前所在的牌堆类型
     * @param toPile 移动后所在的牌堆类型
     * @note 将操作记录到 UndoModel 中，供撤销使用
     */
    void recordMove(CardView* card,
        const cocos2d::Vec2& from,
        const cocos2d::Vec2& to,
        PileType fromPile,
        PileType toPile) {
        _undoModel.pushHistory(card, from, to, fromPile, toPile);
    }

    /**
     * @brief 撤销上一次操作
     * @note 调用 UndoModel 的 undoLast 方法，并触发 onUndoCallback 通知外部刷新UI
     */
    void undo() {
        _undoModel.undoLast();
        if (onUndoCallback) {
            onUndoCallback();
        }
    }

    /**
     * @brief 清空所有操作记录
     */
    void clear() {
        _undoModel.clear();
    }

    /**
     * @brief 判断是否有可撤销的操作
     * @return true 如果有操作可撤销；否则 false
     */
    bool canUndo() const {
        return _undoModel.canUndo();
    }

    /**
     * @brief 设置撤销操作后的回调
     * @param cb 回调函数，在撤销后被调用，用于刷新控制器或视图
     */
    void setUndoCallback(std::function<void()> cb) {
        onUndoCallback = std::move(cb);
    }

private:
    UndoModel _undoModel;                   ///< 管理操作历史的模型对象
    std::function<void()> onUndoCallback;   ///< 撤销后通知外部的回调
};
