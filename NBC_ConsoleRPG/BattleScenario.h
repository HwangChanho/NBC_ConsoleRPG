#pragma once

#include <iostream>
#include <memory>

#include "Player.h"

// ��Ʋ ���ø� �޼��� ����
// ���ø� �޼��� ������ ���� Ŭ�������� �˰����� ��ü Ʋ(���)�� �����ϰ�, 
// ���� Ŭ�������� ���ϴ� �κи� �����ϵ��� �ϴ� ������ �����Դϴ�. 
// �̸� ���� ���� ������ �����ϸ鼭�� ���� ������ �پ��ϰ� ó���� �� �ֽ��ϴ�.
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