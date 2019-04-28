#pragma once

/**
 * Enables the creation of a singleton object by creating a static global instance.
 */
template<class T>
class SingletonObject
{
public:
	/** Default constructor. */
	SingletonObject()
	{
		assert(m_ginstance == nullptr);
		if (m_ginstance == nullptr)
		{
			m_ginstance = static_cast<T*>(this);
		}
	}

	/** Default destructor. */
	virtual ~SingletonObject()
	{
		m_ginstance = nullptr;
	}

	/** Returns a reference to the singleton object. */
	static T& GetObjectReference()
	{
		return *m_ginstance;
	}

	/** Returns the singleton object.  */
	static T* GetObject()
	{
		return m_ginstance;
	}

private:
	/** Global singleton object. */
	static T* m_ginstance;
};

template<class T>
T* SingletonObject<T>::m_ginstance = nullptr;