#include "ChatManager.h"

#include <EclipseEngine/include/Object.h>
#include "ChatMessage.h"
#include "ChatWriter.h"

namespace Eclipse
{
	namespace Chat
	{
		void ChatManager::Post(ChatMessage* message)
		{
			// assign last message
			lastMessage = message;

			// invoke event
			OnMessageReceived.Invoke(message);

			// add to logs.
			chatLogs.push_back(message);
		}

		void ChatManager::_fetchCaches()
		{
			if (!writer)
				writer = object->m_ComponentContainer.GetComponent<ChatWriter>();
			if (!writer)
			{
				return;
			}
		}

		void ChatManager::Reset()
		{
		}

		void ChatManager::Start()
		{
			_fetchCaches();
			OnMessageReceived += [this](auto message) {this->writer->WriteMessage(message); };
		}
	}
}