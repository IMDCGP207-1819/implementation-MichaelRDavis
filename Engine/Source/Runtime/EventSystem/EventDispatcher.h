#pragma once

class Event;

/**
 * 
 */
class EventDispatcher
{
public:
	/**  */
	EventDispatcher(Event* event)
		: m_event(event)
	{

	}

private:
	/**  */
	Event* m_event;
};