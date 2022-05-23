#pragma once

#include <EclipseEngine/include/Component.h>
#include "ChatMessage.h"


namespace Eclipse
{
	namespace Chat
	{
		class ChatManager;

		class ChatWriter : public Components::Component
		{
		public:
			// abstract write function for custom writers.
			virtual void WriteMessage(ChatMessage* message) = 0;
		protected:
			void Reset() override;
			void Awake() final;
		private:
			void _init();
			// instance of chat manager;
			ChatManager* chatManager = nullptr;
		};
	}
}