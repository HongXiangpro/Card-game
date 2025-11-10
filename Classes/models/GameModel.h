#pragma once
#include "cocos2d.h"
#include "CardModel.h"
#include "UndoModel.h"

/**
 * @enum GameState
 * @brief 表示当前游戏状态
 *
 * 该枚举用于区分游戏运行的不同阶段。
 * 用途：
 * 控制游戏逻辑流程（例如暂停、结束、重新开始）
 * 根据状态决定 UI 显示内容或逻辑行为
 */
enum class GameState {
    Idle,        ///< 游戏未开始，等待玩家操作
    Playing,     ///< 游戏进行中
    Paused,      ///< 游戏暂停状态
    GameOver,    ///< 游戏结束（胜利或失败）
};

/**
 * @class GameModel
 * @brief 游戏数据与逻辑核心模型
 *
 * 职责：
 * 管理游戏状态、得分与回合数；
 * 维护卡牌数据模型（CardModel）；
 * 管理撤销操作模型（UndoModel）；
 * 提供游戏逻辑接口（如重置、胜利判断、回合结束、撤销操作）。
 *
 * 使用场景：
 * 游戏主控制器（如 GameScene）中，负责游戏逻辑状态管理；
 * 与视图层（UI 层）交互时提供底层数据支持；
 * 确保逻辑与表现分离，提升可维护性与扩展性。
 *
 * 模块职责：
 * 负责游戏运行状态与数据的维护；
 * 将子模块（卡牌、撤销）独立封装；
 * 可在不修改核心逻辑的前提下增加模式（如计时、排行榜等）。
 */
class GameModel {
public:
    /**
     * @brief 构造函数，初始化默认状态与成员
     */
    GameModel();

    /**
     * @brief 初始化游戏数据
     *
     * 用途：
     *  - 初始化卡牌模型；
     *  - 设置初始状态；
     *  - 准备游戏开始所需数据。
     */
    void initGame();

    /**
     * @brief 重置整局游戏
     *
     * 用途：
     *  - 重新洗牌；
     *  - 重置分数和回合；
     *  - 回到初始状态。
     */
    void resetGame();

    /**
     * @brief 检查胜利条件
     * @return 若达到胜利条件则返回 true，否则返回 false
     *
     * 用途：
     *  - 根据卡牌布局判断是否完成游戏；
     *  - 可在游戏逻辑中周期性调用。
     */
    bool checkWinCondition();

    /**
     * @brief 结束当前回合
     *
     * 用途：
     *  - 更新回合计数；
     *  - 检查状态变化；
     *  - 用于多回合游戏逻辑中。
     */
    void endTurn();

    /**
     * @brief 撤销上一步操作
     *
     * 用途：
     *  - 调用 UndoModel 恢复前一状态；
     *  - 支持玩家撤回误操作；
     *  - 维护操作历史。
     */
    void undoLastMove();

    // ===== Getter & Setter =====

    /**
     * @brief 获取卡牌模型引用
     * @return 卡牌数据模型（CardModel）的引用
     */
    CardModel& getCardModel() { return _cardModel; }

    /**
     * @brief 获取撤销模型引用
     * @return 撤销模型（UndoModel）的引用
     */
    UndoModel& getUndoModel() { return _undoModel; }

    /**
     * @brief 获取当前游戏状态
     * @return 当前游戏状态枚举值（GameState）
     */
    GameState getState() const { return _state; }

    /**
     * @brief 设置游戏状态
     * @param s 要设置的新状态
     */
    void setState(GameState s) { _state = s; }

    /**
     * @brief 获取当前得分
     * @return 当前得分（整数）
     */
    int getScore() const { return _score; }

    /**
     * @brief 增加分数
     * @param delta 分数增量（可正可负）
     */
    void addScore(int delta) { _score += delta; }

private:
    GameState _state = GameState::Idle; ///< 当前游戏状态
    int _score = 0;                     ///< 当前分数
    int _turnCount = 0;                 ///< 当前回合数

    CardModel _cardModel;               ///< 卡牌数据模型
    UndoModel _undoModel;               ///< 撤销操作模型
};
