#pragma once

/**
 * Base class for all events.
 */
class Event
{
public:
	/** Default constructor. */
	Event(int64_t eventID);

	/** Returns the event ID. */
	inline int64_t GetEventID() const
	{
		return m_EventID;
	}

private:
	/** The unique ID for this event. */
	int64_t m_EventID;
};