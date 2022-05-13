#include "NetworkChatMessage.h"

#include <string>

namespace Eclipse
{
	namespace Chat
	{
		std::string NetworkChatMessage::ToString()
		{
#ifdef NETWORKING_MODULE
			std::string return_value = {};
			return_value += content;
			return_value += " ";
			return_value += senderAddress;
			return return_value;

#else
			return "";
#endif
		}

		NetworkChatMessage::NetworkChatMessage(std::string& message, std::string& senderIp, time_t received)
		{
			content = message;
			senderAddress = senderIp;
			timeReceived = received;
		}
	}
}