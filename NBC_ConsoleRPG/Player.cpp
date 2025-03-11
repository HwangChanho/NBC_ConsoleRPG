#include "Player.h"
#include "PlayerState.h"
#include "WeaponStrategy.h"

Player::Player()
{
  currentWeapon = nullptr;
  currentState = make_shared<NormalState>();
}

void Player::setWeapon(shared_ptr<WeaponStrategy> weapon)
{
  if (!weapon) return;
  currentWeapon = weapon;
}

void Player::setState(shared_ptr<PlayerState> state)
{
  if (!state) return;
  currentState = state;
}

void Player::ReduceHP(int amount)
{
  if (CurrentHP - amount >= 0)
  {
    CurrentHP -= amount;
  }
}

void Player::attack()
{
  if (!currentWeapon) return;
  currentWeapon->useWeapon();
  currentState->handleAttack(*this);
  cout << "АјАн!" << endl;
}