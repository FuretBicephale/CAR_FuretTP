#ifndef _FTP_THREAD_H
#define _FTP_THREAD_H

#include <pthread.h>
#include "exception/Exception.h"

namespace FTP {

	///
	/// \class FTP::Thread<T>
	/// \ingroup system
	/// \brief Thread managment class
	///
	/// Enscapsulate POSIX thread (pthread). Template parameter is the class to launch in a thread. this one need to implement method void run()
	///
	template<class T>
	class Thread {

	public:
		/// \brief Create new thread with class instance target of type T
		Thread(T* target) : _class(target) {

		}

		/// \brief Launch thread
		void run() {
			ProxyArgs* arg = new ProxyArgs();
			arg->_class = _class;

			pthread_create(&_thread, nullptr, proxy, arg);
		}



	private:
		struct ProxyArgs {
			T* _class;
		};

		static void* proxy(void* arg) {
			ProxyArgs* arg_cast = (ProxyArgs*)arg; // get arguments from proxy
			try {
				arg_cast->_class->run(); // run the main methods of thread class
			}
			catch(const Exception& e) { // if uncaught exception arise here
				std::cerr << "Exception caught" << std::endl;
				std::cerr << e.getMessage() << std::endl;
				if(e.getFile() != nullptr)
					std::cerr << "Line " << e.getLine() << " in file " << e.getFile() << std::endl;
				arg_cast->_class->close(); // close thread class
			}

			delete arg_cast;
			return nullptr;
		}

		T* _class;
		pthread_t _thread;

	};
}
#endif
