#include "ChatWriter.h"

#include <EclipseEngine/include/Core.h>
#include <EclipseEngine/include/Object.h>

#include "ChatManager.h"

namespace Eclipse
{
	namespace Chat
	{
		void ChatWriter::_init()
		{
			if (!chatManager)
			{
				chatManager = object->m_ComponentContainer.GetComponent<ChatManager>();
			}
			if (!chatManager)
			{
				External::Debug::DebugAPI::Error("Failed to retrieve chat manager - ChatWriter.Init()");
				return;
			}

			chatManager->OnMessageReceived.AddListener([this](ChatMessage* message) {this->WriteMessage(message); });
		}

		void ChatWriter::Reset(){}

		void ChatWriter::Awake()
		{
			_init();
		}
	}
}
