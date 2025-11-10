#pragma once
#include "cocos2d.h"
#include <vector>

/**
 * @struct CardConfig
 * @brief 单张卡牌的配置结构
 *
 * 描述一张卡牌的基本信息，用于关卡布局。
 * 主要职责：
 * 保存卡牌点数（CardFace）和花色（CardSuit）
 * 保存卡牌在界面上的位置（Position）
 * 使用场景：
 * 关卡配置文件解析后，生成卡牌对象时使用
 */
struct CardConfig {
    int CardFace;            ///< 卡牌点数，使用 CardFaceType 枚举对应的整数
    int CardSuit;            ///< 卡牌花色，使用 CardSuitType 枚举对应的整数
    cocos2d::Vec2 Position; ///< 卡牌在界面上的位置（坐标）
};

/**
 * @struct LevelConfig
 * @brief 关卡配置结构
 *
 * 描述一关的卡牌布局信息，包括桌面和堆叠区。
 * 主要职责：
 * 保存桌面（Playfield）和堆叠区（Stack）的卡牌列表
 * 使用场景：
 * 从关卡配置文件加载时生成，用于创建界面上的卡牌布局
 * 模块职责：
 * 负责存储关卡配置数据
 */
struct LevelConfig {
    std::vector<CardConfig> Playfield; ///< 桌面区卡牌列表
    std::vector<CardConfig> Stack;     ///< 堆叠区卡牌列表
};
