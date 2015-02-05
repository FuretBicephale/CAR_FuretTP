#ifndef _FURETTP_PACKET_H
#define _FURETTP_PACKET_H

#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cctype>
namespace FuretTP {

	class Packet {

	public:
		Packet();
		Packet(const Packet& that);
		~Packet();
		Packet& operator=(const Packet& that);

		unsigned int getSize() const;
		const char* getBuffer() const;

		void rawWrite(const char* buffer, unsigned int length);

		Packet& operator<<(const std::string& str);

		Packet& operator>>(std::string& str);

		friend std::ostream& operator<<(std::ostream& stream, const Packet& packet);


	private:
		const unsigned int BaseAlloc = 64;
		const unsigned int FactorAlloc = 2;

		void _checkAlloc(unsigned int required);

		char* _buffer;
		unsigned int _cursor;
		unsigned int _allocated;
		unsigned int _readCursor;
	};

	std::ostream& operator<<(std::ostream& stream, const Packet& packet);
}
#endif
