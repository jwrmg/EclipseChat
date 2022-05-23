#pragma once
#include <EclipseEngine/include/Component.h>
#include <functional>

#include "ChatManager.h"

namespace Eclipse
{
	namespace Chat
	{
		class ChatInterface : public Components::Component
		{
		public:
			void StartInterface();
			virtual void Send(const std::string& message) = 0;
		private:
			void _fetchCaches();
		protected:
			ChatManager* chatManager = nullptr;
			virtual void ConnectInterface() = 0;
			
			void Reset() override;
		};
	}
}
