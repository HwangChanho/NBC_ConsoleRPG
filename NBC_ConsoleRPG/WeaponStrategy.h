#pragma once

#include <iostream>
#include <memory>

using namespace std;

// ���� ���� ����
// ���� ������ �˰��� ���� ĸ��ȭ�Ͽ�, 
// Ŭ���̾�Ʈ�� ������ �˰����� ��Ÿ�ӿ� ������ �� �ֵ��� ���ݴϴ�.
class WeaponStrategy
{
public:
  virtual void useWeapon() = 0;
  virtual ~WeaponStrategy() {}; // ���� �Ҹ��� �߰��ؾ� leak �ȳ�
};

class Sword : public WeaponStrategy
{
public:
  virtual void useWeapon() override;
};

class Bow : public WeaponStrategy
{
public:
  virtual void useWeapon() override;
};

class Magic : public WeaponStrategy
{
public:
  virtual void useWeapon() override;
};