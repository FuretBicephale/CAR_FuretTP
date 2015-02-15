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
				THROW(SystemException, "Unable open file \""+std::string(_pathname+directory_entry->d_name)+"\"", errno);
			}

			switch (stat.st_mode & S_IFMT) {
			case S_IFDIR:
				entry.permission += "d";
				break;
			default:
				entry.permission += "-";
				break;
			}

			entry.permission += stat.st_mode & S_IRUSR ? "r" : "-";
			entry.permission += stat.st_mode & S_IWUSR ? "w" : "-";
			entry.permission += stat.st_mode & S_IXUSR ? "x" : "-";

			entry.permission += stat.st_mode & S_IRGRP ? "r" : "-";
			entry.permission += stat.st_mode & S_IWGRP ? "w" : "-";
			entry.permission += stat.st_mode & S_IXGRP ? "x" : "-";

			entry.permission += stat.st_mode & S_IROTH ? "r" : "-";
			entry.permission += stat.st_mode & S_IWOTH ? "w" : "-";
			entry.permission += stat.st_mode & S_IXOTH ? "x" : "-";

			entry.size = stat.st_size;
			entry.name = directory_entry->d_name;
#define FORMAT_BUFFER_SIZE 64
			char bufferData[FORMAT_BUFFER_SIZE];
			struct tm timeinfo;
			tzset();
			localtime_r(&(stat.st_mtim.tv_sec), &timeinfo);
			strftime(bufferData, FORMAT_BUFFER_SIZE, "%h %e %R", &timeinfo);
			entry.lastModification = bufferData;

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
