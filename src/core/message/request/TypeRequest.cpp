#include "core/message/request/TypeRequest.h"

using namespace FuretTP;

TypeRequest::TypeRequest(Type type) : Request(TypeRequest::CommandName), _type(type) {

}

TypeRequest::Type TypeRequest::getType() const {
	return _type;
}
