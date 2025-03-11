#pragma once

#include <iostream>
#include <memory>

class NormalState;
class BurserkState;
class Player;

using namespace std;

// �÷��̾� ���� ����
// ���� ������ ��ü�� ���� ���¿� ���� �ൿ�� ������ �� �ֵ��� ���ݴϴ�.
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