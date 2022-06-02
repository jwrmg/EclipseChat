#include "ConsoleChatWriter.h"
#include "ChatMessage.h"

#include <EclipseEngine/include/Console.h>

namespace Eclipse
{
    namespace Chat
    {
        void ConsoleChatWriter::WriteMessage(ChatMessage* message)
        {
            Engine::Console::WriteLine(message->ToString());
            Engine::Console::ConsoleBeep(500, 100);
        }
    }
}