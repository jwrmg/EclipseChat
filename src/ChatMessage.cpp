#include "ChatMessage.h"

#include <EclipseEngine/include/Core.h>

namespace Eclipse
{
	namespace Chat
	{
		std::string ChatMessage::ToString()
		{
			return content;
		}
	}
}