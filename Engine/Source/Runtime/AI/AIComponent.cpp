#include "stdafx.h"
#include "AIComponent.h"
#include "AIBehavior.h"

AIComponent::AIComponent()
{
	m_behavior = std::make_unique<AIBehavior>();
}

AIComponent::~AIComponent()
{

}
