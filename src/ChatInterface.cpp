#include "ChatInterface.h"

#include <EclipseEngine/include/Object.h>

#include <EclipseEngine/include/Core.h>

namespace Eclipse
{
	namespace Chat
	{
		void ChatInterface::StartInterface()
		{
			_fetchCaches();
			ConnectInterface();
		}

		void ChatInterface::_fetchCaches()
		{
			if (!chatManager)
			{
				chatManager = object->m_ComponentContainer.GetComponent<ChatManager>();
			}
			if (!chatManager)
			{
				External::Debug::DebugAPI::Error("Chat Interface - Failed to cache chat manager.");
			}
		}

		void ChatInterface::Reset()
		{
			chatManager = nullptr;
		}
	}
}