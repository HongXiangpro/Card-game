#include "GameModel.h"
#include "../configs/models/CardResConfig.h"

USING_NS_CC;

GameModel::GameModel()
    : _cardModel(), _undoModel(&_cardModel) // 先初始化cardModel再给undoModel传引用
{
    _state = GameState::Idle;
    _score = 0;
    _turnCount = 0;
}

void GameModel::initGame() {
    // 初始化牌堆
    // 清空所有牌堆
    _cardModel.getPileRef(PileType::PlayField).clear();
    _cardModel.getPileRef(PileType::HandPile).clear();
    _cardModel.getPileRef(PileType::TopCards).clear();

    // 清空历史记录
    _undoModel.clear();

    // 例如：初始化手牌或发牌逻辑
    // （可调用 CardResConfig 创建 CardView）
    _state = GameState::Playing;
    _score = 0;
    _turnCount = 1;
}

void GameModel::resetGame() {
    initGame();
}

bool GameModel::checkWinCondition() {
    // 当桌面牌为空则胜利
    return _cardModel.getPileRef(PileType::PlayField).empty();
}

void GameModel::endTurn() {
    _turnCount++;
}

void GameModel::undoLastMove() {
    _undoModel.undoLast();
}
