#include "stdafx.h"
#include "Component.h"

Component::Component()
{
	m_isActive = true;
}

Component::~Component()
{

}

void Component::InitializeComponent()
{

}

void Component::UpdateComponent(float deltaTime)
{
	if (m_isActive)
	{

	}
}

void Component::EnableComponent()
{
	m_isActive = true;
}

void Component::DisableComponent()
{
	m_isActive = false;
}
