#pragma once
#include "Character.h"
class Warrior :
    public Character
{
public:
    Warrior();
    ~Warrior();

public:
    void Attack() const override;

    void DoubleSlash() const;// 전사의 전용스킬
};

