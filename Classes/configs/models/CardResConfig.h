#pragma once
#include <string>

/**
 * @enum CardSuitType
 * @brief 卡牌花色类型枚举
 *
 * 表示一张扑克牌的花色。
 * CST_NONE 表示无效或未设置的花色。
 */
enum CardSuitType
{
    CST_NONE = -1,       ///< 无效花色
    CST_CLUBS,           ///< 梅花
    CST_DIAMONDS,        ///< 方块
    CST_HEARTS,          ///< 红桃
    CST_SPADES,          ///< 黑桃
    CST_NUM_CARD_SUIT_TYPES ///< 花色类型总数
};

/**
 * @enum CardFaceType
 * @brief 卡牌点数类型枚举
 *
 * 表示一张扑克牌的点数。
 * CFT_NONE 表示无效或未设置的点数。
 */
enum CardFaceType
{
    CFT_NONE = -1, ///< 无效点数
    CFT_ACE,       ///< A
    CFT_TWO,       ///< 2
    CFT_THREE,     ///< 3
    CFT_FOUR,      ///< 4
    CFT_FIVE,      ///< 5
    CFT_SIX,       ///< 6
    CFT_SEVEN,     ///< 7
    CFT_EIGHT,     ///< 8
    CFT_NINE,      ///< 9
    CFT_TEN,       ///< 10
    CFT_JACK,      ///< J
    CFT_QUEEN,     ///< Q
    CFT_KING,      ///< K
    CFT_NUM_CARD_FACE_TYPES ///< 点数类型总数
};

/**
 * @class CardResConfig
 * @brief 卡牌资源路径配置类
 *
 * 提供静态方法获取卡牌图片资源路径，包括：
 * 卡牌背景图
 * 数字图（根据点数、花色和大小）
 * 花色图
 *
 * 模块职责：
 * 负责卡牌资源路径生成，不涉及加载或显示逻辑
 * 如需修改路径或资源命名规则，只需修改本类
 * 可增加更多资源类型（如特殊效果、动画等）
 */
class CardResConfig
{
public:
    /**
     * @brief 获取卡牌背景图片路径
     * @return std::string 背景图片相对路径
     */
    static std::string getCardBackground()
    {
        return "res/res/card_general.png";
    }

    /**
     * @brief 获取卡牌数字图片路径
     *
     * 根据点数、花色和字体大小，返回对应的数字图片路径。
     *
     * @param face 卡牌点数
     * @param suit 卡牌花色（用于判断颜色：红色/黑色）
     * @param isBig 是否使用大号字体
     * @return std::string 数字图片路径
     */
    static std::string getNumberImage(CardFaceType face, CardSuitType suit, bool isBig)
    {
        std::string sizeStr = isBig ? "big" : "small";
        std::string colorStr = (suit == CST_DIAMONDS || suit == CST_HEARTS) ? "red" : "black";
        std::string faceStr;

        switch (face)
        {
        case CFT_ACE:   faceStr = "A"; break;
        case CFT_TWO:   faceStr = "2"; break;
        case CFT_THREE: faceStr = "3"; break;
        case CFT_FOUR:  faceStr = "4"; break;
        case CFT_FIVE:  faceStr = "5"; break;
        case CFT_SIX:   faceStr = "6"; break;
        case CFT_SEVEN: faceStr = "7"; break;
        case CFT_EIGHT: faceStr = "8"; break;
        case CFT_NINE:  faceStr = "9"; break;
        case CFT_TEN:   faceStr = "10"; break;
        case CFT_JACK:  faceStr = "J"; break;
        case CFT_QUEEN: faceStr = "Q"; break;
        case CFT_KING:  faceStr = "K"; break;
        default:        faceStr = "A"; break;
        }

        return "res/res/number/" + sizeStr + "_" + colorStr + "_" + faceStr + ".png";
    }

    /**
     * @brief 获取卡牌花色图片路径
     *
     * 根据花色返回对应的花色图路径。
     *
     * @param suit 卡牌花色
     * @return std::string 花色图片路径，如果无效花色返回空字符串
     */
    static std::string getSuitImage(CardSuitType suit)
    {
        switch (suit)
        {
        case CST_CLUBS:    return "res/res/suits/club.png";
        case CST_DIAMONDS: return "res/res/suits/diamond.png";
        case CST_HEARTS:   return "res/res/suits/heart.png";
        case CST_SPADES:   return "res/res/suits/spade.png";
        default:           return "";
        }
    }
};
