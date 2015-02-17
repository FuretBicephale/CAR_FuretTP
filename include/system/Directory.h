#ifndef _FTP_DIRECTORY_H
#define _FTP_DIRECTORY_H

#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <vector>

#include "exception/SystemException.h"

namespace FTP {

	///
	/// \class Directory
	/// \ingroup system
	/// \brief Directory management classx
	///
	/// Enscapsulate C directory reader functions. Allow to list the content directory
	///
	class Directory {

	public:
		///
		/// \class Entry
		/// \ingroup system
		/// \brief Entry in directory
		///
		/// Structure which contains entry information
		///
		struct Entry {
		public:
			/// \brief file permission in Unix presentation (like -rwxr-x---)
			std::string permission;
			/// \brief file size
			unsigned int size;
			/// \brief file name
			std::string name;
			/// \brief last modification date in format month day hh:mm
			std::string lastModification;
		};

		Directory();
		~Directory();

		/// \brief open a directory
		/// \param pathname of the directory
		void open(const std::string& pathname);
		/// \brief list the directory contents. Need previously be openend
		/// \param entries : a vector which be fill with all the entries of the opened directory
		void list(std::vector<Entry>& entries);
		/// \brief close directory
		void close();

	private:
		DIR* _directory;
		std::string _pathname;
	};
}
#endif
