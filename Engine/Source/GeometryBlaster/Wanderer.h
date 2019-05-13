#pragma once

#include "GameObject/Entity.h"

class AIComponent;

class Wanderer : public Entity
{
public:
	Wanderer();
	~Wanderer();

private:
	std::unique_ptr<AIComponent> m_behaviorComp;
};