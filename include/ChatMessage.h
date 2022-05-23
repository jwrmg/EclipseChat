#pragma once
#include <string>

namespace Eclipse
{
	namespace Chat
	{
		class ChatMessage
		{
		public:
			virtual ~ChatMessage() = default;
			std::string content = {};
			virtual std::string ToString();
		};
	}
}