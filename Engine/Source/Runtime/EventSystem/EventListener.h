#pragma once

class Event;

/**
 * 
 */
class IEventListener
{
public:
	/**  */
	virtual void OnEvent(Event* event) = 0;
};