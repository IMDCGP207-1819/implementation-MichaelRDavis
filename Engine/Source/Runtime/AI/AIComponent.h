#pragma once

#include "GameObject/Component.h"

class AIBehavior;

/**
 * 
 */
class AIComponent : public Component
{
public:
	/** Default constructor. */
	AIComponent();

	/** Default destructor. */
	~AIComponent();

	/** Component behavior. */
	std::unique_ptr<AIBehavior> m_behavior;
};