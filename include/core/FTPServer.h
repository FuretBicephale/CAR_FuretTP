#ifndef _FTP_SERVER_H
#define _FTP_SERVER_H

#include "core/ServerConfiguration.h"

#include "network/tcp/Listener.h"
#include "system/Thread.h"
#include "core/Client.h"

#include <iostream>

namespace FuretTP {

	class FTPServer {

	public:
        FTPServer(const ServerConfiguration& configuration);

		void run();

        const ServerConfiguration& getConfiguration() const;


	private:
        const ServerConfiguration&  _configuration;

	};
}

#endif
