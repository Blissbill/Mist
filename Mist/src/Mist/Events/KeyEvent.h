#pragma once
#include "mtpch.h"

#include "Event.h"

namespace Mist
{
	class MIST_API KeyEvent : public Event
	{
	public:
		inline int GetKeyKode() const { return m_KeyKode; }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard);
	protected:
		KeyEvent(int keykode)
			:m_KeyKode(keykode) {}

		int m_KeyKode;
	};

	class MIST_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keykode, int repeatCount)
			: KeyEvent(keykode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent::" << m_KeyKode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyPressed);
	private:
		int m_RepeatCount;
	};

	class MIST_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keykode)
			: KeyEvent(keykode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent::" << m_KeyKode;
			return ss.str();
		}
		EVENT_CLASS_TYPE(Keyreleased);
	};
}