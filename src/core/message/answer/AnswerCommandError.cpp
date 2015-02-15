#include "core/message/answer/AnswerCommandError.h"

using namespace FTP;

AnswerUnimplemented::AnswerUnimplemented() : Answer(AnswerUnimplemented::Code) {

}

AnswerAuthRequired::AnswerAuthRequired() : Answer(AnswerAuthRequired::Code) {

}

AnswerFileUnavailable::AnswerFileUnavailable() : Answer(AnswerFileUnavailable::Code) {

}
