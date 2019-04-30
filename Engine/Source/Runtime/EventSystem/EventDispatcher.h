#pragma once

class Event;

class EventDispatcher
{
public:
	EventDispatcher(Event* event)
		: m_event(event)
	{

	}

	void Disptach(std::function<bool(T&)> func)
	{

	}

private:
	Event* m_event;
};