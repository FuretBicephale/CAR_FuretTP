#ifndef _FURETTP_DIRECTORY_H
#define _FURETTP_DIRECTORY_H

#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <vector>

#include "exception/SystemException.h"

namespace FuretTP {

	class Directory {

	public:
		struct Entry {
		public:
			std::string permission;
			unsigned int size;
			std::string name;


		};

		Directory();
		~Directory();

		void open(const std::string& pathname);
		void list(std::vector<Entry>& entries);
		void close();

	private:
		DIR* _directory;
		std::string _pathname;
	};
}
#endif
