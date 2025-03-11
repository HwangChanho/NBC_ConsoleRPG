#include "PlayerState.h"
#include "Player.h"

void NormalState::handleAttack(Player& player)
{
  cout << "NormalState!" << endl;
  ++AttackCount;

  if (AttackCount > 5)
  {
    player.setState(make_shared<BurserkState>());
  }
}

void BurserkState::handleAttack(Player& player)
{
  cout << "BurserkState!" << endl;
  if (player.GetHP() < 30)
  {
    player.setState(make_shared<NormalState>());
  }
}