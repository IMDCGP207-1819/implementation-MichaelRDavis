#include "stdafx.h"
#include "Seeker.h"
#include "AI/AIComponent.h"

Seeker::Seeker()
{
	m_behaviorComp = std::make_unique<AIComponent>();
	AddComponent(typeid(m_behaviorComp), m_behaviorComp.get());
	m_behaviorComp->SetOwner(this);
}

Seeker::~Seeker()
{

}
