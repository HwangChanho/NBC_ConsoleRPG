#pragma once

#include <iostream>
#include <memory>

#include "Player.h"

// 배틀 템플릿 메서드 패턴
// 템플릿 메서드 패턴은 상위 클래스에서 알고리즘의 전체 틀(골격)을 정의하고, 
// 하위 클래스에서 변하는 부분만 구현하도록 하는 디자인 패턴입니다. 
// 이를 통해 공통 로직은 재사용하면서도 세부 사항은 다양하게 처리할 수 있습니다.
class BattleScenario
{
public:
  virtual ~BattleScenario() = default;

  void runScenario() {
    this->setup();
    this->playerAction();
    this->enemyAction();
    this->conclude();
  }

protected:
  virtual void setup() = 0;
  virtual void playerAction() = 0;
  virtual void enemyAction() = 0;
  virtual void conclude() = 0;
};

class BossBattleScenario : public BattleScenario
{
public:
  BossBattleScenario(Player* p) : player(p) {}

protected:
  void setup() override
  {
    cout << "Boss setup!" << endl;
  }

  void playerAction() override
  {
    cout << "Boss playerAction!" << endl;
    if (player)
    {
      player->attack();
    }
  }

  void enemyAction() override
  {
    cout << "Boss enemyAction!" << endl;
  }

  void conclude() override
  {
    cout << "Boss conclude!" << endl;
  }

private:
  Player* player;
};

class MobBattleScenario : public BattleScenario
{
public:
  MobBattleScenario(Player* p) : player(p) {}

protected:
  void setup() override
  {
    cout << "Mob setup!" << endl;
  }

  void playerAction() override
  {
    cout << "Mob playerAction!" << endl;
    if (player)
    {
      player->attack();
    }
  }

  void enemyAction() override
  {
    cout << "Mob enemyAction!" << endl;
  }

  void conclude() override
  {
    cout << "Mob conclude!" << endl;
  }

private:
  Player* player;
};