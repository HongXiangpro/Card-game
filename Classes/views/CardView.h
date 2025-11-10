#pragma once
#include "cocos2d.h"
#include "../configs/models/CardResConfig.h"

/**
 * @class CardView
 * @brief 卡牌显示节点类
 *
 * CardView 用于在游戏界面中显示单张卡牌，包括背景、点数和花色图标。
 * 主要职责：
 * 根据点数和花色显示卡牌图像
 * 提供对卡牌基本信息（点数、花色）的访问接口
 * 使用场景：
 * 创建手牌、桌面牌或堆叠区的卡牌显示节点
 * 模块职责：
 * 负责卡牌的界面显示
 * 可根据需要增加动画效果、点击事件或高亮显示等
 */
class CardView : public cocos2d::Node {
public:
    /**
     * @brief 创建 CardView 实例
     * @param faceIndex 卡牌点数索引，对应 CardFaceType 枚举
     * @param suit 卡牌花色
     * @param isBig 是否使用大号点数字体
     * @return 返回 CardView* 指针，如果初始化失败返回 nullptr
     */
    static CardView* create(int faceIndex, CardSuitType suit, bool isBig = true);

    /**
     * @brief 获取卡牌点数索引
     * @return int 卡牌点数索引
     */
    int getFaceIndex() const { return _faceIndex; }

    /**
     * @brief 获取卡牌花色
     * @return CardSuitType 卡牌花色
     */
    CardSuitType getSuit() const { return _suit; }

    /**
     * @brief 获取卡牌背景精灵
     * @return cocos2d::Sprite* 背景 Sprite 指针
     */
    cocos2d::Sprite* getBackground() const { return _background; }

protected:
    /**
     * @brief 初始化 CardView
     * @param faceIndex 卡牌点数索引
     * @param suit 卡牌花色
     * @param isBig 是否大号字体
     * @return bool 初始化成功返回 true，否则 false
     */
    bool init(int faceIndex, CardSuitType suit, bool isBig);

private:
    int _faceIndex = 0;                  ///< 卡牌点数索引，对应 CardFaceType
    CardSuitType _suit = CardSuitType::CST_CLUBS; ///< 卡牌花色
    bool _isBig = true;                  ///< 是否大号点数字体

    cocos2d::Sprite* _background = nullptr; ///< 卡牌背景 Sprite
    cocos2d::Sprite* _number = nullptr;     ///< 点数字 Sprite
    cocos2d::Sprite* _suitSprite = nullptr;///< 花色 Sprite
};
