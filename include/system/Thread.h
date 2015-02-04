#ifndef _FURETTP_THREAD_H
#define _FURETTP_THREAD_H

#include <pthread.h>
#include "exception/Exception.h"

namespace FuretTP {

	template<class T>
	class Thread {

	public:
		Thread(T* target) : _class(target) {

		}

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
			ProxyArgs* arg_cast = (ProxyArgs*)arg;
			try {
				arg_cast->_class->run();
			}
			catch(const Exception& e) {
				std::cerr << e.getMessage() << std::endl;
				std::cerr << "Exception caught in client thread" << std::endl;
				if(e.getFile() != nullptr)
					std::cerr << "Line " << e.getLine() << " in file " << e.getFile() << std::endl;
			}

			delete arg_cast;
			return nullptr;
		}

		T* _class;
		pthread_t _thread;

	};
}
#endif
