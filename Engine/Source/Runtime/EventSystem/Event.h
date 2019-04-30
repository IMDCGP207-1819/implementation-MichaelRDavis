#pragma once

class Event
{
public:
	Event(int64_t eventID);

	inline int64_t GetEventID() const
	{
		return m_EventID;
	}

private:
	int64_t m_EventID;
};