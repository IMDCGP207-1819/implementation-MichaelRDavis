#include "stdafx.h"
#include "Wanderer.h"
#include "AI/AIComponent.h"

Wanderer::Wanderer()
{
	m_behaviorComp = std::make_unique<AIComponent>();
	AddComponent(typeid(m_behaviorComp), m_behaviorComp.get());
	m_behaviorComp->SetOwner(this);
}

Wanderer::~Wanderer()
{

}
