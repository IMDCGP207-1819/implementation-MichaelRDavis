#include "stdafx.h"
#include "AIBehavior.h"
#include "GameObject/Entity.h"

AIBehvaior::AIBehvaior()
{

}

AIBehvaior::~AIBehvaior()
{

}

void AIBehvaior::SetOwner(Entity* newOwner)
{
	m_owner = newOwner;
}
