#pragma once

#include <iostream>
#include <memory>

class NormalState;
class BurserkState;
class Player;

using namespace std;

// 플레이어 상태 패턴
// 상태 패턴은 객체의 내부 상태에 따라 행동을 변경할 수 있도록 해줍니다.
class PlayerState
{
public:
  virtual void handleAttack(Player& player) = 0;
  virtual ~PlayerState() {}
};

class NormalState : public PlayerState {
public:
  virtual void handleAttack(Player& player) override;

private:
  int AttackCount = 0;
};

class BurserkState : public PlayerState {
public:
  virtual void handleAttack(Player& player) override;

private:
  int AttackCount = 0;
};