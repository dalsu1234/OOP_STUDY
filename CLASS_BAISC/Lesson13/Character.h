#pragma once
class Character
{
protected:
	int mHP;

public:
	Character();
	virtual ~Character();

public:
	virtual void Attack() const;
};

