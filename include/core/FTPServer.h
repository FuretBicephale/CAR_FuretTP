#ifndef _FTP_SERVER_H
#define _FTP_SERVER_H

#include "core/FTPServerConfiguration.h"

#include "network/tcp/Listener.h"
#include "system/Thread.h"
#include "core/Client.h"

#include <iostream>

namespace FuretTP {

	class FTPServer {

	public:
		FTPServer(const FTPServerConfiguration& configuration);

		void run();

		const FTPServerConfiguration& getConfiguration() const;


	private:
		const FTPServerConfiguration&  _configuration;

	};
}

#endif
