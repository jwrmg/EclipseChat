#pragma once
#include <EclipseEngine/include/Component.h>
#include "ChatInterface.h"

#ifdef NETWORKING_MODULE
#include <EclipseNetworking/include/NetworkPacket.h>
#endif


namespace Eclipse
{
	namespace Chat
	{
		class NetworkChatInterface : public ChatInterface
		{
		public:
			void Send(const std::string& message) override;
#ifdef NETWORKING_MODULE
			void Receive(Networking::NetworkPacket& packet);
#endif
		protected:
			void ConnectInterface() override;
		};
	}
}