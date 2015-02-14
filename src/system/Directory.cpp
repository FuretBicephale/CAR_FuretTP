#include "system/Directory.h"

using namespace FuretTP;



Directory::Directory() : _directory(nullptr), _pathname() {

}

Directory::~Directory() {
	close();
}

void Directory::open(const std::string& pathname) {
	if((_directory = opendir(pathname.c_str())) == nullptr) {
		_directory = nullptr;
		THROW(SystemException, "Unable open directory \""+pathname+"\"", errno);
	}
	_pathname = pathname;
}

void Directory::list(std::vector<Entry>& entries) {
	if(_directory != nullptr) {
		struct dirent* directory_entry;
		while ((directory_entry = readdir(_directory)) != nullptr) {
			Entry entry;
			struct stat stat;

			if(::stat(std::string(_pathname+directory_entry->d_name).c_str(),&stat) == -1) {
				THROW(SystemException, "Unable open directory \""+std::string(_pathname+directory_entry->d_name)+"\"", errno);
			}

			entry.permission = "-rw-r--r--";
			entry.size = stat.st_size;
			entry.name = directory_entry->d_name;


			entries.push_back(entry);
		}
	}
}

void Directory::close() {
	if(_directory != nullptr) {
		closedir(_directory);
		_directory = nullptr;
	}
}
