#pragma once
#include <string>
#include <vector>
#include <EclipseEngine/include/Component.h>
#include <EclipseEngine/include/EclipseEvent.h>

#include "ChatWriter.h"

namespace Eclipse
{
	namespace Chat
	{
		class ChatManager : public Components::Component
		{
		protected:
			void Start() override;
		public:
			void Post(ChatMessage* message);
			// event for when a message has been received.
			Engine::EclipseEvent<ChatMessage*> OnMessageReceived = {};
			// last message sent to the chat.
			ChatMessage* lastMessage = nullptr;
		private:

			void _fetchCaches();
		protected:
			void Reset() override;
		private:
			std::vector<ChatMessage*> chatLogs = {};
			ChatWriter* writer = nullptr;
		};
	}
}
