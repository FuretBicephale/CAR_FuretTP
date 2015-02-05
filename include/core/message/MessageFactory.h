#ifndef _FTP_MESSAGE_FACTORY_H
#define _FTP_MESSAGE_FACTORY_H

#include <memory>

#include "core/message/Message.h"

namespace FuretTP {

    class MessageFactory {

	public:
		/// Return an FTPMessage. Receiver is responsable of the return delete
        static std::unique_ptr<Message> eval(const Packet& packet);

	private:
		//Singleton
        MessageFactory();
        MessageFactory(const MessageFactory& that);
        MessageFactory& operator=(const MessageFactory& that);
	};
}

#endif
