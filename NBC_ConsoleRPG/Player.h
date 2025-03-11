#pragma once

#include <iostream>
#include <memory>

class WeaponStrategy;
class PlayerState;

using namespace std;

class Player
{
public:
  Player();

  void setWeapon(shared_ptr<WeaponStrategy> weapon);
  void setState(shared_ptr<PlayerState> state);
  void ReduceHP(int amount);
  inline int GetHP() { return CurrentHP; }
  void attack();
private:
  shared_ptr<WeaponStrategy> currentWeapon;
  shared_ptr<PlayerState> currentState;

  int CurrentHP = 100;
};