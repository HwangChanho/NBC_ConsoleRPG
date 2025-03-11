#pragma once

#include <iostream>
#include <memory>
#include <string>

using namespace std;

// 아이템 빌더 패턴
// 빌더 패턴은 복잡한 객체 생성 과정을 캡슐화해 생성과 표현을 분리하고, 
// 단계별로 객체를 구성할 수 있게 해서 코드의 가독성과 유연성을 높이는 데 쓰입니다.
class Item
{
public:
	void setName(string _name) { name = _name; }
	void setHPRecovery(int _hpRecovery) { hpRecovery = _hpRecovery; }
	void setMPRecovery(int _mpRecovery) { mpRecovery = _mpRecovery; }
	void setAttackBoost(int _attackBoost) { attackBoost = _attackBoost; }
	void setDefenseBoost(int _defenseBoost) { defenseBoost = _defenseBoost; }
	void showDetail()
	{
		if (name == "") return;
		cout << "name: " << name << endl;
		if (hpRecovery == 0) return;
		cout << "hpRecovery: " << hpRecovery << endl;
		if (mpRecovery == 0) return;
		cout << "mpRecovery: " << mpRecovery << endl;
		if (attackBoost == 0) return;
		cout << "attackBoost: " << attackBoost << endl;
		if (defenseBoost == 0) return;
		cout << "defenseBoost: " << defenseBoost << endl;
	}

private:
	string name;
	int hpRecovery;
	int mpRecovery;
	int attackBoost;
	int defenseBoost;
};

class ItemBuilder
{
public:
	virtual ~ItemBuilder() {}
	virtual ItemBuilder* setName(string name) = 0;
	virtual ItemBuilder* setHPRecovery(int recoveryRate) = 0;
	virtual ItemBuilder* setMPRecovery(int recoveryRate) = 0;
	virtual ItemBuilder* setAttackBoost(int boostAmount) = 0;
	virtual ItemBuilder* setDefenseBoost(int boostAmount) = 0;
	virtual shared_ptr<Item> getResult() = 0;
};

class PotionBuilder : public ItemBuilder
{
public:
	PotionBuilder() { reset(); }
	void reset() { item = make_shared<Item>(); }

	virtual ItemBuilder* setName(string name) override
	{
		item->setName(name);
		return this;
	}

	virtual ItemBuilder* setHPRecovery(int recoveryRate) override
	{
		item->setHPRecovery(recoveryRate);
		return this;
	}

	virtual ItemBuilder* setMPRecovery(int recoveryRate) override
	{
		item->setMPRecovery(recoveryRate);
		return this;
	}

	virtual ItemBuilder* setAttackBoost(int boostAmount) override
	{
		item->setAttackBoost(boostAmount);
		return this;
	}

	virtual ItemBuilder* setDefenseBoost(int boostAmount) override
	{
		item->setDefenseBoost(boostAmount);
		return this;
	}

	virtual shared_ptr<Item> getResult() override
	{
		shared_ptr<Item> result = item;
		reset();
		return result;
	}

private:
	shared_ptr<Item> item;
};

class WeaponBuilder : public ItemBuilder
{
public:
	WeaponBuilder() { reset(); }
	void reset() { item = make_shared<Item>(); }

	virtual ItemBuilder* setName(string name) override
	{
		item->setName(name);
		return this;
	}

	virtual ItemBuilder* setHPRecovery(int recoveryRate) override
	{
		item->setHPRecovery(recoveryRate);
		return this;
	}

	virtual ItemBuilder* setMPRecovery(int recoveryRate) override
	{
		item->setMPRecovery(recoveryRate);
		return this;
	}

	virtual ItemBuilder* setAttackBoost(int boostAmount) override
	{
		item->setAttackBoost(boostAmount);
		return this;
	}

	virtual ItemBuilder* setDefenseBoost(int boostAmount) override
	{
		item->setDefenseBoost(boostAmount);
		return this;
	}

	virtual shared_ptr<Item> getResult() override
	{
		shared_ptr<Item> result = item;
		reset();
		return result;
	}

private:
	shared_ptr<Item> item;
};

class ItemDirector {
public:
	void constructBasicHealingPotion(const shared_ptr<ItemBuilder>& _builder) {
		builder = _builder;

		builder->setName("HealingPotion")
			->setHPRecovery(1);
	}

	void constructBasicSword(const shared_ptr<ItemBuilder>& _builder) {
		builder = _builder;

		builder->setName("Normal Sword")
			->setAttackBoost(10);
	}

private:
	shared_ptr<ItemBuilder> builder;
};
