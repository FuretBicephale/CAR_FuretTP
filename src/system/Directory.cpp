#include "system/Directory.h"

using namespace FuretTP;

Directory::Entry::Entry(const std::string& name, char type) : _name(name), _type(type) {

}

const std::string& Directory::Entry::getName() const {
	return _name;
}

char Directory::Entry::getType() const {
	return _type;
}

Directory::Directory() : _directory(nullptr) {

}

Directory::~Directory() {
	close();
}

void Directory::open(const std::string& pathname) {
	if((_directory = opendir(pathname.c_str())) == nullptr) {
		_directory = nullptr;
		THROW(SystemException, "Unable open directory \""+pathname+"\"", errno);
	}
}

void Directory::list(std::vector<Entry>& entries) {
	if(_directory != nullptr) {
		struct dirent* directory_entry;
		while ((directory_entry = readdir(_directory)) != nullptr) {
			  entries.push_back(Entry(directory_entry->d_name, directory_entry->d_type));
		}
	}
}

void Directory::close() {
	if(_directory != nullptr) {
		closedir(_directory);
		_directory = nullptr;
	}
}
