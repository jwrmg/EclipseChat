#include "NetworkChatInterface.h"

#ifdef NETWORKING_MODULE
#include <EclipseNetworking/include/NetworkManager.h>
#include <EclipseNetworking/include/NetworkIdentifiers.h>

#include <EclipseEngine/include/EclipseTime.h>

#include "NetworkChatMessage.h"
#endif
namespace Eclipse
{
	namespace Chat
	{
		void NetworkChatInterface::Send(const std::string& message)
		{
#ifdef NETWORKING_MODULE
			Networking::EclipsePacket packet(static_cast<unsigned char>(Networking::NetworkIdentifiers::EID_MESSAGE));

			packet.Write(RakNet::RakString(message.c_str()));

			packet.reliability = RELIABLE_ORDERED;
			packet.priority = HIGH_PRIORITY;

			Networking::NetworkManager::Instance->SendPacket(&packet, 0, RakNet::UNASSIGNED_SYSTEM_ADDRESS, true, 0);
#else
			External::Debug::DebugAPI::Debug("Networking is not installed.");
#endif
		}
		// oh lmao
#ifdef NETWORKING_MODULE
		void NetworkChatInterface::Receive(Networking::EclipsePacket& packet)
		{

			unsigned char id = packet.Read<unsigned char>();

			std::string message = packet.Read<RakNet::RakString>();

			std::string senderIp = packet.m_packet_->systemAddress.ToString(true);
			time_t timeReceived = Engine::EclipseTime::GetTime();
			if (chatManager)
			{
				chatManager->Post(new NetworkChatMessage(message, senderIp, timeReceived));
			}
		}

#endif
		void NetworkChatInterface::ConnectInterface()
		{
#ifdef NETWORKING_MODULE
			auto handle = Networking::NetworkManager::Instance->handler.GetReceivedHandle((unsigned int)Networking::NetworkIdentifiers::EID_MESSAGE);
			if (!handle)
			{
				Networking::NetworkManager::Instance->handler.OnPacketReceived.emplace((unsigned int)Networking::NetworkIdentifiers::EID_MESSAGE, new Engine::EclipseEvent<Networking::EclipsePacket&>);
			}

			handle->AddListener([this](Networking::EclipsePacket& packet) {this->Receive(packet); });
#else
			External::Debug::DebugAPI::Debug("Networking is not installed.");
#endif
		}
	}
}