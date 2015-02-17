#ifndef _FTP_PACKET_H
#define _FTP_PACKET_H

#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cctype>
namespace FTP {

	///
	/// \class Packet
	/// \ingroup system
	/// \brief
	///
	/// Class which contains data. Packet are used to send and receive message from sockets
	///
	class Packet {

	public:
		/// \brief create empty packet
		Packet();
		/// \brief create new packet and copy 'that' contents into it
		Packet(const Packet& that);
		/// \brief destroy packet and free memory
		~Packet();
		/// \brief copy content of another packet into current packet
		Packet& operator=(const Packet& that);

		unsigned int getSize() const;
		const char* getBuffer() const;

		/// \brief write a raw buffer of size 'length' into the packet
		void rawWrite(const char* buffer, unsigned int length);

		/// \brief write a string at the end of the packet content
		Packet& operator<<(const std::string& str);

		/// \brief get the next word of the packet content
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

	/// \brief display the content of the packet on the stream
	std::ostream& operator<<(std::ostream& stream, const Packet& packet);
}
#endif
