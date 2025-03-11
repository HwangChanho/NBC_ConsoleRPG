#pragma once

#include <iostream>
#include <memory>

using namespace std;

// 무기 전략 패턴
// 전략 패턴은 알고리즘 군을 캡슐화하여, 
// 클라이언트가 실행할 알고리즘을 런타임에 결정할 수 있도록 해줍니다.
class WeaponStrategy
{
public:
  virtual void useWeapon() = 0;
  virtual ~WeaponStrategy() {}; // 가상 소멸자 추가해야 leak 안남
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