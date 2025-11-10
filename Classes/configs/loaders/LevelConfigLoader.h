/**
 * @class LevelConfigLoader
 * @brief 关卡配置加载器
 *
 * 负责从指定 JSON 配置文件中读取关卡信息，并生成对应的关卡数据模型（LevelConfig）。
 * 主要职责：
 * 读取关卡 JSON 文件
 * 解析卡牌初始布局
 * 生成 LevelConfig 对象供游戏逻辑使用
 *
 * 使用场景：
 * 在游戏启动或进入新关卡时，通过该类加载关卡数据。
 * 例如：LevelConfig config = LevelConfigLoader::loadLevelConfig("Resources/configs/level1.json");
 */

#pragma once

#include "../models/LevelConfig.h"
#include "json/document.h"

class LevelConfigLoader {
public:

    /**
     * @brief 加载关卡配置
     *
     * 从指定路径的 JSON 文件读取关卡配置，并解析生成 LevelConfig 对象。
     *
     * @param filePath JSON 配置文件路径（相对路径或绝对路径）
     * @return LevelConfig 解析后的关卡配置对象
     */
    static LevelConfig loadLevelConfig(const std::string& filePath);
};
