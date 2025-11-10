#pragma once
#include "cocos2d.h"
#include "CardView.h"
#include <functional>

class GameController; // 前向声明

/**
 * @class GameView
 * @brief 游戏主视图层，负责显示游戏界面和卡牌交互。
 *
 * 职责：
 * 展示主牌堆、底牌堆、备用堆等区域
 * 处理UI层的点击事件绑定
 *
 * 使用场景：
 * 初始化游戏界面
 * 绑定卡牌点击回调，实现用户交互
 */
class GameView : public cocos2d::Node {
public:
    /**
     * @brief 初始化游戏视图
     * @return 初始化是否成功
     */
    virtual bool init() override;

    CREATE_FUNC(GameView);

    /**
     * @brief 设置控制器
     * @param controller 游戏控制器指针
     */
    void setController(GameController* controller) { _controller = controller; }

    /**
     * @brief 隐藏开始按钮
     */
    void hideStartButton();

    /**
     * @brief 获取卡牌显示层
     * @return 指向卡牌显示的 Layer
     */
    cocos2d::Layer* getCardLayer() const { return _cardLayer; }

    /**
     * @brief 设置卡牌点击回调
     * @param cb 回调函数，参数为 CardView* 和是否手牌区 bool
     */
    void setCardClickCallback(const std::function<void(CardView*, bool)>& cb);

    /**
     * @brief 为指定卡牌添加触摸监听
     * @param card 指定卡牌
     * @param isHand 是否为手牌区卡牌
     */
    void addCardTouchListener(CardView* card, bool isHand);

private:
    GameController* _controller = nullptr; ///< 游戏控制器指针，用于转发逻辑操作
    cocos2d::Layer* _cardLayer;            ///< 卡牌显示层
    cocos2d::MenuItemImage* _startButton;  ///< 开始按钮
    cocos2d::MenuItemImage* _undoButton;   ///< 撤销按钮
    cocos2d::Menu* _menu;                  ///< 菜单层

    std::function<void(CardView*, bool)> _onCardClick; ///< 卡牌点击回调
};
