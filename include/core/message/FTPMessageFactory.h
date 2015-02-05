#ifndef _FTP_MESSAGE_FACTORY_H
#define _FTP_MESSAGE_FACTORY_H

#include <memory>

#include "core/message/FTPMessage.h"

namespace FuretTP {

	class FTPMessageFactory {

	public:
		/// Return an FTPMessage. Receiver is responsable of the return delete
		static std::unique_ptr<FTPMessage> eval(const Packet& packet);

	private:
		//Singleton
		FTPMessageFactory();
		FTPMessageFactory(const FTPMessageFactory& that);
		FTPMessageFactory& operator=(const FTPMessageFactory& that);
	};
}

#endif
