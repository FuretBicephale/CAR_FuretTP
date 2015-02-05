#include "network/Packet.h"

using namespace FuretTP;

Packet::Packet() : _buffer(nullptr), _cursor(0), _allocated(0) {
	_buffer = (char*)malloc(BaseAlloc);
	_allocated = BaseAlloc;
}

Packet::Packet(const Packet& that) : _buffer(nullptr), _cursor(that._cursor), _allocated(that._allocated) {
	_buffer = (char*)malloc(that._allocated);
	memcpy(_buffer, that._buffer, _cursor);
}

Packet::~Packet() {
	free(_buffer);
}

Packet& Packet::operator=(const Packet& that) {
	_cursor = that._cursor;
	_allocated = that._allocated;
	_buffer = (char*)malloc(that._allocated);
	memcpy(_buffer, that._buffer, _cursor);
}

void Packet::_checkAlloc(unsigned int required) {
	while(_cursor+required >= _allocated) {
		_allocated *= 2;
		_buffer = (char*)realloc(_buffer, _allocated);
	}
}

unsigned int Packet::getSize() const {
	return _cursor;
}

const char* Packet::getBuffer() const {
	return _buffer;
}

void Packet::rawWrite(const char* buffer, unsigned int length) {
	_checkAlloc(length);

	memcpy(_buffer+_cursor, buffer, length);
}

Packet& Packet::operator<<(const std::string& str) {
	_checkAlloc(str.size());
	memcpy(_buffer+_cursor, str.c_str(), str.size());
	_cursor += str.size();
	return *this;
}

std::ostream& FuretTP::operator<<(std::ostream& stream, const Packet& packet) {
	stream.write(packet._buffer, packet._cursor);
	return stream;
}
