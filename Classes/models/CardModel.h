#pragma once
#include "cocos2d.h"
#include "../views/CardView.h"
#include <vector>
#include <algorithm>

/**
 * @enum PileType
 * @brief 牌堆类型枚举
 *
 * 描述卡牌所在的不同牌区类型。
 * PlayField: 桌面牌堆
 * HandPile: 手牌堆
 * TopCards: 顶部牌栈（可操作的堆叠区域）
 */
enum class PileType {
    PlayField,
    HandPile,
    TopCards
};

/**
 * @class CardModel
 * @brief 卡牌数据模型
 *
 * 管理游戏中所有牌区的卡牌数据，包括桌面牌、手牌和顶部牌栈。
 * 主要职责：
 * 提供对各牌区的增删查操作
 * 维护牌区内卡牌顺序
 * 使用场景：
 * 由游戏逻辑层调用，驱动界面上的 CardView 更新
 * 模块职责：
 * 管理牌区数据，不涉及界面渲染逻辑
 * 可扩展更多牌区或操作
 */
class CardModel {
public:
    CardModel() = default;
    ~CardModel() = default;

    /**
     * @brief 获取当前顶部牌
     * @return CardView* 指向当前顶部牌的指针，如果牌区为空则返回 nullptr
     */
    CardView* getCurrentTopCard() const;

    /**
     * @brief 根据卡牌查找其所属牌区
     * @param card 指向目标卡牌的 CardView 指针
     * @return PileType 该卡牌所属的牌区类型
     */
    PileType getPileOf(CardView* card) const;

    /**
     * @brief 从指定牌区移除卡牌
     * @param pile 目标牌区
     * @param card 要移除的卡牌指针
     */
    void removeFromPile(PileType pile, CardView* card);

    /**
     * @brief 向指定牌区添加卡牌
     * @param pile 目标牌区
     * @param card 要添加的卡牌指针
     */
    void addToPile(PileType pile, CardView* card);

    /**
     * @brief 获取牌区引用
     * @param pile 指定牌区
     * @return std::vector<CardView*>& 返回对应牌区的卡牌列表引用
     */
    std::vector<CardView*>& getPileRef(PileType pile);

private:
    std::vector<CardView*> _playField;   ///< 桌面牌列表
    std::vector<CardView*> _handPile;    ///< 手牌列表
    std::vector<CardView*> _topCards;    ///< 顶部牌栈列表
};
