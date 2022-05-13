#include "ConsoleChatWriter.h"
#include "ChatMessage.h"

#include <EclipseEngine/include/Console.h>

namespace Eclipse
{
	namespace Chat
	{
		void ConsoleChatWriter::WriteMessage(ChatMessage* message)
		{
			std::stringstream ss;
			ss << message->ToString();
			Engine::Console::WriteLine(ss);
			Engine::Console::ConsoleBeep(500, 100);
		}
	}
}
