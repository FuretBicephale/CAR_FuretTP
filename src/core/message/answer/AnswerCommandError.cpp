#include "core/message/answer/AnswerCommandError.h"

using namespace FTP;

AnswerUnimplemented::AnswerUnimplemented() : Answer(AnswerUnimplemented::Code) {

}

AnswerFileUnavailable::AnswerFileUnavailable() : Answer(AnswerFileUnavailable::Code) {

}
