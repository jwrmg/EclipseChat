#pragma once

#include "ChatMessage.h"

namespace Eclipse
{
	namespace Chat
	{
		class NetworkChatMessage final : public ChatMessage
		{
		public:
			std::string senderAddress{};
			time_t timeReceived{};
			std::string ToString() override;

			NetworkChatMessage(std::string& message, std::string& senderIp, time_t received);
		};
	}
}
