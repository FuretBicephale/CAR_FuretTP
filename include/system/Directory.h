#ifndef _FURETTP_DIRECTORY_H
#define _FURETTP_DIRECTORY_H

#include <string>
#include <sys/types.h>
#include <dirent.h>
#include <vector>

#include "exception/SystemException.h"

namespace FuretTP {

	class Directory {

	public:
		class Entry {
		public:
			Entry(const std::string& name, char type);

			const std::string& getName() const;
			char getType() const;
		private:
			std::string _name;
			char _type;
		};

		Directory();
		~Directory();

		void open(const std::string& pathname);
		void list(std::vector<Entry>& entries);
		void close();

	private:
		DIR* _directory;
	};
}
#endif
