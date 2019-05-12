#pragma once

#include "GameObject/Entity.h"

class AIComponent;

class Seeker : public Entity
{
public:
	Seeker();
	~Seeker();

private:
	std::unique_ptr<AIComponent> m_behaviorComp;
};