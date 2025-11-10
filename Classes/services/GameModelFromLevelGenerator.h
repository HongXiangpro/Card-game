#pragma once
#include "../models/GameModel.h"
#include "../configs/models/LevelConfig.h"
#include "../models/CardModel.h"

/**
 * @class GameModelFromLevelGenerator
 * @brief 根据关卡配置生成游戏模型（GameModel）的工具类
 *
 * 主要职责：
 * 将 LevelConfig 中的关卡配置解析成 CardModel 或 GameModel 中的数据
 * 不直接涉及游戏逻辑，仅负责从配置生成模型数据
 *
 * 使用场景：
 * 游戏初始化时，根据关卡 JSON 配置文件生成对应的卡牌模型
 * 在关卡重置或加载关卡时使用
 *
 * 模块设计：
 * 负责配置到模型的转换
 * 便于扩展不同类型的关卡生成逻辑
 */
class GameModelFromLevelGenerator {
public:
    /**
     * @brief 从关卡配置生成卡牌模型
     *
     * 根据传入的 LevelConfig 填充 CardModel 中的数据，使其与关卡布局一致。
     *
     * @param cfg 关卡配置对象，包含 Playfield 和 Stack 的卡牌信息
     * @param outModel 输出的 CardModel 对象，将被填充为对应关卡布局
     */
    static void populateCardModelFromConfig(const LevelConfig& cfg, CardModel& outModel);
};
