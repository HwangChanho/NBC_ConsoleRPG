#include <iostream>
#include <memory>

#include "Player.h"
#include "BattleScenario.h"
#include "WeaponStrategy.h"
#include "Item.h"

using namespace std;

int main()
{
  auto player = make_unique<Player>();
  player->setWeapon(make_shared<Sword>());

  auto scenario = make_unique<MobBattleScenario>(player.get());
  scenario->runScenario();

  ItemDirector ItemDirector;
  shared_ptr<ItemBuilder> potionBuilder = make_shared<PotionBuilder>();
  ItemDirector.constructBasicHealingPotion(potionBuilder);
  shared_ptr<Item> HealingPotion = potionBuilder->getResult();
  HealingPotion->showDetail();

  return 0;
}
