#pragma once

#include "ChatWriter.h"

namespace Eclipse
{
	namespace Chat
	{
		class ConsoleChatWriter : public ChatWriter
		{
		protected:
			void WriteMessage(ChatMessage* message) override;
		};
	}
}